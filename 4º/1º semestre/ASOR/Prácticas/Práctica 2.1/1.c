#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *err;

	if (setuid(0) == -1)
	{
		perror(err);
	}

	exit(EXIT_SUCCESS);
}