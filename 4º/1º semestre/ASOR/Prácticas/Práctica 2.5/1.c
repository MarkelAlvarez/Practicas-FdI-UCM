#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* Comprobar argumento. */
	if (argc != 2)
	{
		printf("Uso: %s <host>\n", argv[0]);

		exit(EXIT_FAILURE);
	}

	/* Reservar estructuras. */
	struct addrinfo hints;
	struct addrinfo *result;
	struct addrinfo *rp;

	/* Preparar y establecer los hints. */
	memset(&hints, 0, sizeof(struct addrinfo));

	hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
	hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
	hints.ai_protocol = 0;          /* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;
	
	/* Obtener la información. */
	int s = getaddrinfo(argv[1], NULL, &hints, &result);
	
	/* Comprobar errores. */
	if (s != 0)
	{
		printf("Error (getaddrinfo()): %s\n", gai_strerror(s));
		
		exit(EXIT_FAILURE);
	}

	char host[NI_MAXHOST];

	/* getaddrinfo() devuelve una lista de estructuras de dirección. */
	/* Examinar cada estructura. */
	for (rp = result; rp != NULL; rp = rp->ai_next)
	{
		/* Obtener la información a partir del host numérico. */
		getnameinfo(rp->ai_addr, rp->ai_addrlen, host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
		printf("Dirección: %s (familia %d; tipo %d)\n", host, rp->ai_family, rp->ai_socktype);
	}

	freeaddrinfo(result);

	exit(EXIT_SUCCESS);
}