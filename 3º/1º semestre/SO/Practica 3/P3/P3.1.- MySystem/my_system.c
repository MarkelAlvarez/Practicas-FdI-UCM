#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int estado;
	pid_t hijo;
	char *comando;

	if (argc!=2)
	{
		fprintf(stderr, "Usage: %s <command>\n", argv[0]);
		exit(1);
	}

	comando = argv[1];

	switch (hijo = fork())
	{
		case -1:
			estado = -1;
			return estado;
		case 0:
			execl("/bin/sh", "sh", "-c", comando, (char *) NULL);
			return 1;
		default:
			while(waitpid(hijo, &estado, 0) == -1)
			{
				if(EINTR != errno)
				{
					estado = -1;
					break;
				}
			}
			return estado;
	}
}