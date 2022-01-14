#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 128

int main(int argc, char **argv)
{
	/* Comprobar argumentos. */
	if (argc != 3)
	{
		printf("Uso: %s <host> <puerto>\n", argv[0]);
		
		exit(EXIT_FAILURE);
	}
	
	/* Preparar las estructuras. */
	struct addrinfo hints;
	struct addrinfo *result;
	
	memset(&hints, 0, sizeof(struct addrinfo));
	
	hints.ai_family 	= AF_UNSPEC;
	hints.ai_socktype 	= SOCK_STREAM;
	hints.ai_flags 		= AI_PASSIVE;
	hints.ai_protocol 	= 0;
	hints.ai_addrlen 	= 0;
	hints.ai_canonname 	= NULL;
	hints.ai_addr 		= NULL;
	hints.ai_next 		= NULL;

	/* Obtener la dirección de socket. */
	int s = getaddrinfo(argv[1], argv[2], &hints, &result);
	if (s != 0)
	{
		printf("Error: getaddrinfo(): %s\n", gai_strerror(s));
		exit(EXIT_FAILURE);
	}
	
	/* Crear el socket. */
	int socket_d = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (socket_d == -1)
	{
		perror("Error: socket()\n");
		exit(EXIT_FAILURE);
	}

	/* Conectar al socket. */
	s = connect(socket_d, result->ai_addr, result->ai_addrlen);
	if (s == -1)
	{
		perror("Error: connect()\n");
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		char str[BUFFER_SIZE];
		fgets(str, BUFFER_SIZE, stdin);
		str[strlen(str)-1] = '\0';

		/* Enviar el comando. */
		ssize_t send_result = send(socket_d, str, sizeof(str), 0);
		if (send_result == -1)
		{
			perror("Error: sendto()\n");
			exit(EXIT_FAILURE);
		}
		
		/* Recibir una posible respuesta. */
		if (strcmp(str, "Q") != 0)
		{		
			char buffer[BUFFER_SIZE + 1];
			
			/* Recibir la respuesta. */
			ssize_t recv_result = recv(socket_d, buffer, BUFFER_SIZE, 0);
			if (recv_result == -1)
			{
				perror("Error: recvfrom()\n");
				exit(EXIT_FAILURE);
			}
			
			buffer[recv_result] = '\0';
			
			printf("Respuesta: %s\n", buffer);
		}
		else
		{
			// Close connection.
			close(socket_d);
			exit(EXIT_SUCCESS);
		}
	}
	
	exit(EXIT_SUCCESS);
}