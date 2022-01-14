#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	const int flags = O_RDWR | O_CREAT | O_TRUNC;
	const mode_t mask = S_IWGRP | S_IXOTH;
	const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IXOTH;
	
	umask(mask);

	int fd = open("Práctica 2.2/7.txt", flags, mode);

	if (fd == -1)
	{
		perror("Error");
		return -1;
	}
	else
	{
		close(fd);
		printf("El fichero con descriptor %d se ha creado correctamente.\n", fd);
	}
	
	return 0;
}