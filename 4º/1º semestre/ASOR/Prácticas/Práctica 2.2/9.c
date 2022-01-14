#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <sys/sysmacros.h>

int main()
{
	int fd;
	struct stat buf;
	char *file_name = "Práctica 2.2/9.txt";

	fd = open(file_name, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return -1;
	}
	
	if (fstat(fd, &buf) == -1)
	{
		perror("Error al obtener los atributos del archivo");
		return -1;
	}
	else
	{
		printf("Major: %d\n", major(buf.st_dev));
		printf("Minor: %d\n", minor(buf.st_dev));
		printf("Inode: %ld\n", buf.st_ino);

		char *type;
		if (S_ISLNK(buf.st_mode)) {
			type = "enlace simbólico";
		}
		else if (S_ISDIR(buf.st_mode))
		{
			type = "directorio";
		}
		else if (S_ISREG(buf.st_mode))
		{
			type = "fichero regular";
		}
		printf("Modo: %s\n", type);
		
		time_t time = buf.st_atime;
		struct tm * tma = localtime(& time);
		printf("Hora de último acceso: %d:%d:%d\n", tma->tm_hour, tma->tm_min, tma->tm_sec);
	}

	close(fd);

	return 0;
}