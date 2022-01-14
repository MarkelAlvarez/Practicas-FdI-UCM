#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	sigset_t mask;

	// Block SIGINT and SIGSTP signals
	if (sigemptyset(&mask) == -1)
	{
		perror("sigemptyset()");
	}

	if (sigaddset(&mask, SIGINT) == -1)
	{
		perror("sigaddset()");
	}

	if (sigaddset(&mask, SIGTSTP) == -1)
	{
		perror("sigaddset()");
	}

	if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1)
	{
		printf("Error: no pudo establecerse la máscara de bloqueo de las señales SIGINT y SIGTSTP.");
		perror("sigprocmask()");

		exit(EXIT_FAILURE);
	}

	// Sleep for X seconds
	char * sleep_secs = getenv("SLEEP_SECS");
	if (sleep_secs == NULL)
	{
		printf("Error: no se pudo encontrar la variable de entorno SLEEP_SECS.");
		exit(EXIT_FAILURE);
	}
	sleep(atoi(sleep_secs));

	// Check if SIGINT or SIGTSTP has been received
	sigset_t pending;
	sigemptyset(&pending);
	if (sigpending(&mask) == -1)
	{
		perror("sigpending()");
		exit(EXIT_FAILURE);
	}

	if (sigismember(&pending, SIGINT))
	{
		printf("Recibida la señal SIGINT.\n");
	}

	if (sigismember(&pending, SIGTSTP))
	{
		// If signal has been received, then proceed to unblock it
		printf("Recibida la señal SIGTSTP.\n");

		if (sigdelset(&mask, SIGINT) == -1)
		{
			perror("sigdelset()");
			exit(EXIT_FAILURE);
		}

		if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1)
		{
			printf("Error: no pudo establecerse la máscara de desbloqueo de la señal SIGTSTP.");
			perror("sigprocmask()");

			exit(EXIT_FAILURE);
		}
	}
	
	printf("Se ha desbloqueado la señal SIGTSTP.\n");
	
	return 0;
}