#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MAX 255

int main()
{
	for (int i = 0; i < ERR_MAX; i++)
	{
		printf("ERROR %d: %s\n", i, strerror(i));
	}

	exit(EXIT_SUCCESS);
}