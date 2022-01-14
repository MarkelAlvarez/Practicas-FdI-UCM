#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid < 0)
	{
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("Proceso hijo con PID %d y PPID %d\n", getpid(), getppid());		

		// close stdin, stdout and stderr
		close(0);
		close(1);
		close(2);

		// open /dev/null
		int fd = open("/dev/null", O_RDONLY);
		if (fd < 0)
		{
			perror("open()");
			exit(EXIT_FAILURE);
		}
		// redirect stdin to /dev/null
		dup2(fd, 0);

		// open /tmp/daemon.out
		int fd1 = open("/tmp/daemon.out", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd1 < 0)
		{
			perror("open()");
			exit(EXIT_FAILURE);
		}
		// redirect stdout to /tmp/daemon.out
		dup2(fd1, 1);

		// open /tmp/daemon.err
		int fd2 = open("/tmp/daemon.err", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 0)
		{
			perror("open()");
			exit(EXIT_FAILURE);
		}
		// redirect stderr to /tmp/daemon.err
		dup2(fd2, 2);

		if (execvp(argv[1], argv + 1) == -1)
		{
			printf("Error: no se pudo ejecutar el comando.");
			perror("execvp()");

			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		printf("Proceso padre con PID %d\n", getpid());
	}
	
	return 0;
}