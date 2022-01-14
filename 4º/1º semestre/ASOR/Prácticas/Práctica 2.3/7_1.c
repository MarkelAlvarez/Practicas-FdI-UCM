// Escribir dos versiones, una con system(3) y otra con execvp(3), de un programa
// que ejecute otro programa que se pasará como argumento por línea de comandos.
// En cada caso, se debe imprimir la cadena “El comando terminó de ejecutarse”
// después de la ejecución.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	// check if there is a second argument
	if (argc < 2)
	{
		printf("Usage: %s <command>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();
	switch (pid)
	{
		case -1:
			printf("Error: no se pudo crear el proceso hijo.");
			perror("fork()");

			exit(EXIT_FAILURE);
		case 0:
			// Ejecutar el comando.
			if (execvp(argv[1], argv + 1) == -1)
			{
				printf("Error: no se pudo ejecutar el comando.");
				perror("execvp()");

				exit(EXIT_FAILURE);
			}
		default:
			waitpid(pid, NULL, 0);
			printf("El comando terminó de ejecutarse con execvp().\n");
	}
	
	return 0;
}