#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		perror("Error: debe especificar la ruta del fichero o directorio como argumento del programa.");

		return -1;
	}

	int fd = open(argv[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		perror("Error: no se pudo abrir el fichero o directorio.");

		return -1;
	}

	dup2(fd, STDOUT_FILENO);
	printf("ASOR mola\n");
	close(fd);

	return 0;
}