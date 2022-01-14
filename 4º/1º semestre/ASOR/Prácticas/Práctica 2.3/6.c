#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_attributes();

int main()
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
		printf("\nProceso hijo con PID %d y PPID %d\n", getpid(), getppid());
		
		// Change working directory to /tmp
		if (chdir("/tmp") == -1)
		{
			perror("chdir()");
			exit(EXIT_FAILURE);
		}

		display_attributes();
	}
	else
	{
		printf("Proceso padre con PID %d\n", getpid());

		display_attributes();
		
		// We wait for the child to finish before the father. If not, the child is assigned PPID 1.
		waitpid(pid, NULL, 0);
	}
	
	return 0;
}

void display_attributes()
{
	int max_files;
	pid_t pid, ppid, pgid, sid;

	pid = getpid();
	ppid = getppid();
	pgid = getpgid(pid);
	sid = getsid(pid);
		
	// Get maximun amount of files that can be opened by the process
	struct rlimit rl;
	if (getrlimit(RLIMIT_NOFILE, &rl) == -1)
	{
		printf("Error: no se pudieron obtener los datos de límites de recursos.");
		perror("getrlimit()");
		exit(EXIT_FAILURE);
	}
	max_files = rl.rlim_cur;
	
	printf("Process id: %d\n", pid);
	printf("Parent process id: %d\n", ppid);
	printf("Process group id: %d\n", pgid);
	printf("Session id: %d\n", sid);

	printf("Max files: %d\n", max_files);
	printf("Current directory: %s\n", getcwd(NULL, pid));
}