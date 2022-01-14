#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("User UID: %d\n", getuid());
	printf("User EUID: %d\n", geteuid());
	
	return 0;
}