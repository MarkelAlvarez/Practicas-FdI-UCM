#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

const char *path = "./ej3-mkfifo";

int main(int argc, char const *argv[])
{
	int fd;
	struct stat sb;

	if(argc != 2)
	{
		printf("Usage: %s <nombre_tuberia>\n", argv[0]);
		return 1;
	}

	mode_t m = S_IRWXU | S_IRWXG | S_IRWXO;
	if(mkfifo(path, m) == -1)
	{
		perror("mkfifo");
		return 1;
	}

	fd = open(path, O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}

	size_t s = strlen(argv[1]);
	if (write(fd, argv[1], strlen(argv[1]) == -1))
	{
		perror("write");
		return 1;
	}

	if(fstat(fd, &sb) == -1)
	{
		perror("fstat");
		return 1;
	}

	printf("%s:\n", argv[1]);
	printf("\tType: %s\n", sb.st_mode & S_IFREG ? "Regular file" : "Unknown");
	printf("\tSize: %ld\n", sb.st_size);
	printf("\tInode: %ld\n", sb.st_ino);
	printf("\tDevice: %ld\n", sb.st_dev);
	printf("\tNumber of links: %ld\n", sb.st_nlink);
	printf("\tUser ID: %d\n", sb.st_uid);
	printf("\tGroup ID: %d\n", sb.st_gid);
	printf("\tDevice type: %ld\n", sb.st_rdev);
	printf("\tBlock size: %ld\n", sb.st_blksize);
	printf("\tNumber of blocks: %ld\n", sb.st_blocks);
	printf("\tLast access: %s", ctime(&sb.st_atime));
	printf("\tLast modification: %s", ctime(&sb.st_mtime));
	printf("\tLast status change: %s", ctime(&sb.st_ctime));

	close(fd);
	
	return 0;
}