#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <nombre_tuberia_anterior>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_CREAT | O_WRONLY, 0666);

	write(fd, argv[1], strlen(argv[1]));
	close(fd);

	return 0;
}