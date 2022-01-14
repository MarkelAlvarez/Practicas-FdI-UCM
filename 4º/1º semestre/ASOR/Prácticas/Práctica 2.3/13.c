// Write a program that performs the scheduled deletion of the executable itself.
// The program will have as an argument the amount of time to wait before deleting the executable.
// The deletion of the executable con be stopped if signal SIGUSR1 is received.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int stop = 0;

static void handler(int signo);

int main(int argc, char *argv[])
{	
	// Check if there are more or less than 2 arguments
	if (argc != 2)
	{
		printf("Usage: %s <time>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	// Prepare the mask to unlock SIGUSR1
	sigset_t mask;
	if (sigemptyset(&mask) == -1)
		perror("sigemptyset()");
	
	if (sigaddset(&mask, SIGUSR1) == -1)
		perror("sigaddset()");
	
	// Unlock SIGUSR1
	if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1)
		perror("sigprocmask()");

	// Prepare and install signal handler
	struct sigaction s;
	s.sa_handler = handler;
	if (sigaction(SIGUSR1, &s, NULL) == -1)
		perror("sigaction()");
	
	// Wait for the signal and check if time has expired
	int i = 0;
	int time = atoi(argv[1]);

	while (i < time && !stop)
	{
		sleep(1);
		i++;
	}

	// Check and delete the executable
	if (stop)
	{
		printf("Aborting...\n");
	}
	else
	{
		printf("Deleting the executable...\n");
		if (unlink(argv[0]) == -1)
			perror("unlink()");
	}

	exit(EXIT_SUCCESS);
}

static void handler(int signal)
{
	if (signal == SIGUSR1)
		stop = 1;
}