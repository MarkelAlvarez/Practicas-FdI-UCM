#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define BUF_SIZE 1024

int main()
{
	int pipe_p_c_fd[2];
	int pipe_c_p_fd[2];

	if (pipe(pipe_p_c_fd) == -1)
	{
		printf("Error: no se pudo crear la tubería de padre a hijo.");
		perror("pipe()");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_c_p_fd) == -1)
	{
		printf("Error: no se pudo crear la tubería de hijo a padre.");
		perror("pipe()");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		printf("Error: no se pudo crear el proceso hijo.");
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	// Hijo
	else if (pid == 0)
	{
		// Cerrar el extremo de escritura de p_c y el de lectura de c_p.
		if (close(pipe_p_c_fd[PIPE_WR]) == -1)
		{
			perror("close()");
		}

		if (close(pipe_c_p_fd[PIPE_RD]) == -1)
		{
			perror("close()");
		}

		int received = 0;
		char buffer[BUF_SIZE + 1];
		ssize_t size = 0;

		while (received < 10)
		{
			// Esperar el mensaje del padre.
			size = read(pipe_p_c_fd[PIPE_RD], &buffer, BUF_SIZE);

			if (size == -1)
			{
				printf("Error: no se pudo leer de la tubería del padre al hijo.");
				perror("read()");
				exit(EXIT_FAILURE);
			}

			received++;

			printf("Recibido: %s\n", buffer);

			// Esperar 1 segundo.
			sleep(1);

			if (write(pipe_c_p_fd[PIPE_WR], "l", 1) == -1)
			{
				printf("Error: no se pudo escribir a la tubería del hijo al padre.");
				perror("write()");
				exit(EXIT_FAILURE);
			}
		}

		if (write(pipe_c_p_fd[PIPE_WR], "q", 1) == -1)
		{
			printf("Error: no se pudo escribir a la tubería del hijo al padre.");
			perror("write()");
			exit(EXIT_FAILURE);
		}

		close(pipe_p_c_fd[PIPE_RD]);
		close(pipe_c_p_fd[PIPE_WR]);
	}
	// Padre
	else
	{
		// Cerrar el extremo de escritura de c_p y el de lectura de p_c.
		if (close(pipe_c_p_fd[PIPE_WR]) == -1)
		{
			perror("close()");
		}
		if (close(pipe_p_c_fd[PIPE_RD]) == -1)
		{
			perror("close()");
		}

		char buffer[BUF_SIZE + 1];
		char child_buffer[1] = { 'l' };
		ssize_t size = 0;

		while (child_buffer[0] != 'q')
		{
			// Leer de la entrada estándar.
			size = read(STDIN_FILENO, & buffer, BUF_SIZE);

			if (size == -1)
			{
				printf("Error: no se pudo leer de la entrada estándar.");
				perror("read()");
				exit(EXIT_FAILURE);
			}

			// Insertar el caracter de fin de cadena en la posición anterior al final, para eliminar el salto de línea.
			buffer[size - 1] = '\0';

			// Enviar el mensaje al hijo.
			if (write(pipe_p_c_fd[PIPE_WR], buffer, size) == -1)
			{
				printf("Error: no se pudo escribir a la tubería del padre al hijo.");
				perror("write()");
				exit(EXIT_FAILURE);
			}

			// Esperar la respuesta del hijo.
			size = read(pipe_c_p_fd[PIPE_RD], child_buffer, 1);

			if (size == -1)
			{
				printf("Error: no se pudo leer de la tubería del hijo al padre.");
				perror("read()");
				exit(EXIT_FAILURE);
			}
		}

		close(pipe_p_c_fd[PIPE_WR]);
		close(pipe_c_p_fd[PIPE_RD]);

		printf("Recibido mensaje de finalización.\n");
	}

	return 0;
}