#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int fd;
	int result;
	char buf[1024];
	struct flock lock;
	time_t now;
	struct tm *tm;

	if (argc != 2) {
		perror("Error: debe especificar la ruta del fichero o directorio como argumento del programa.\n");

		return -1;
	}

	fd = open(argv[1], O_CREAT | O_RDWR, 00777);
	if (fd == -1)
	{
		perror("Error: no se ha podido abrir el archivo.\n");
		return -1;
	}

	result = fcntl(fd, F_GETLK, &lock);
	if (result == -1)
	{
		perror("Error: fcntl.\n");
		return -1;
	}

	if (lock.l_type == F_UNLCK)
	{
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 0;
		lock.l_len = 0;
		lock.l_pid = 0;

		result = fcntl(fd, F_SETLK, &lock);
		if (result == -1)
		{
			perror("Error: fcntl");
			close(fd);
			return -1;
		}

		printf("Cerrojo fijado correctamente.\n");

		now = time(NULL);
		tm = localtime(&now);
		strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", tm);
		printf("Fecha y hora: %s\n", buf);

		write(fd, &buf, strlen(buf));
		sleep(30);

		lock.l_type = F_UNLCK;

		result = fcntl(fd, F_SETLKW, &lock);
		if (result == -1)
		{
			perror("Error: fcntl.\n");
			close(fd);
			return -1;
		}
		else
		{
			printf("Cerrojo liberado correctamente.\n");
		}
	}
	else
	{
		printf("El fichero está bloqueado.\n");
		close(fd);
		return -1;
	}

	close(fd);
	
	return 0;
}