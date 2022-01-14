#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

const char * path_1 = "./ej5-fifo-1";
const char * path_2 = "./ej5-fifo-2";
const int buffer_size = 256;

int main()
{
	int flags = O_RDONLY | O_NONBLOCK;

	int fd1 = open(path_1, flags);
	if(fd1 == -1)
	{
		perror("open 1");
		return 1;
	}

	int fd2 = open(path_2, flags);
	if(fd2 == -1)
	{
		perror("open 2");
		return 1;
	}

	// Preparar el conjunto de descriptores de ficheros y el temporizador.
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(fd1, &fds);
	FD_SET(fd2, &fds);

	timeval tv = {
		.tv_sec = 10,
		.tv_usec = 0
	};

	// Calcular el máximo descriptor de fichero (argumento nfds de select()).
	int nfds = (fd1 > fd2) ? fd1 + 1 : fd2 + 1;

	// Esperar a que haya datos listos para leer.
	int selec = select(nfds, &fds, NULL, NULL, &tv);
	if (selec == -1)
	{
		perror("select()");
	}

	// Comprobar recepción.
	if (selec)
	{
		char buffer[buffer_size + 1] = { 0 };

		if (FD_ISSET(fd1, & fds))
		{
			read(fd1, buffer, buffer_size);
			printf("Leído de FIFO 1: %s", buffer);
		}
		else if (FD_ISSET(fd2, & fds))
		{
			read(fd2, buffer, buffer_size);
			printf("Leído de FIFO 2: %s", buffer);
		}
	}
	else
	{
		printf("No se ha recibido ningún dato nuevo en 10 segundos.");
	}

	close(fd1);
	close(fd2);

	exit(EXIT_SUCCESS);
}