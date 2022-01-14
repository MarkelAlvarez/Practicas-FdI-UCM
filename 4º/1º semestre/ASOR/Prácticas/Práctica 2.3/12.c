#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int sigtint_counter = 0, sigtstp_counter = 0;

static void handler(int signum);

int main(int argc, char *argv[])
{
	struct sigaction s;

	sigemptyset(& s.sa_mask);
	s.sa_flags = SA_RESTART; // Reiniciar funciones si las interrumpe el manejador.

	s.sa_handler = handler;

	// Install handlers
	if (sigaction(SIGINT, &s, NULL) == -1)
	{
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}

	if (sigaction(SIGTSTP, &s, NULL) == -1)
	{
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}

	// Prepare mask to receive SIGINT and SIGTSTP signals
	sigset_t mask;
	if (sigfillset(&mask) == -1)
		perror("sigfillset()");
	if (sigdelset(&mask, SIGINT) == -1)
		perror("sigdelset()");
	if (sigdelset(&mask, SIGTSTP) == -1)
		perror("sigdelset()");
	
	// Loop until a total of 10 signals have been received.
	while (sigtint_counter + sigtstp_counter < 10)
	{
		sigsuspend(&mask);
	}

	// Print the number of times each signal has been received.
	printf("SIGINT: %d\n", sigtint_counter);
	printf("SIGSTP: %d\n", sigtstp_counter);

	exit(EXIT_SUCCESS);
}

static void handler(int signum)
{
	switch (signum)
	{
		case SIGINT:
			sigtint_counter++;
			break;
		case SIGTSTP:
			sigtstp_counter++;
			break;
	}
}