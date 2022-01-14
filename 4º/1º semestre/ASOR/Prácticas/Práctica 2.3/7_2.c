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

	int size = 0;
	for (int i = 0; i < argc; i++)
	{
		size += strlen(argv[i]);
	}

	char command[size];
	sprintf(command, "%s", argv[1]);
	for (int i = 2; i < argc; i++)
	{
		sprintf(command, "%s %s", command, argv[i]);
	}
	
	if (system(command) == -1)
	{
		printf("Error: no se pudo ejecutar el comando.");
		perror("system()");

		exit(EXIT_FAILURE);
	}

	printf("El comando terminó de ejecutarse on system().\n");

	return 0;
}