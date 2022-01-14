// Write a program that shows process identifiers:
// identificador de proceso, de proceso padre, de grupo de procesos y de sesión.
// Mostrar además el número máximo de ficheros que puede abrir el proceso y el directorio de trabajo actual.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>

int main (int argc, char *argv[])
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
	
	return 0;
}