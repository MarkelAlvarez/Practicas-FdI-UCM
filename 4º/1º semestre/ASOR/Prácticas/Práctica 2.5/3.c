#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 128

int main(int argc, char **argv)
{
	/* Comprobar argumentos. */
	if (argc != 4)
	{
		printf("Uso: %s <host> <puerto> <comando>\n", argv[0]);
		
		exit(EXIT_FAILURE);
	}
	
	/* Preparar las estructuras. */
	struct addrinfo hints;
	struct addrinfo *result;
	
	memset(&hints, 0, sizeof(struct addrinfo));
	
	hints.ai_family 	= AF_UNSPEC;
	hints.ai_socktype 	= SOCK_DGRAM;
	hints.ai_flags 		= AI_PASSIVE;
	hints.ai_protocol 	= 0;
	hints.ai_canonname 	= NULL;
	hints.ai_addr 		= NULL;
	hints.ai_next 		= NULL;

	/* Obtener la dirección de socket. */
	int s = getaddrinfo(argv[1], argv[2], & hints, & result);
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
	
	/* Enviar el comando. */
	ssize_t send_result = sendto(socket_d, argv[3], sizeof(argv[3]), 0, result->ai_addr, result->ai_addrlen);
	if (send_result == -1)
	{
		perror("Error: sendto()\n");
		exit(EXIT_FAILURE);
	}
	
	/* Recibir una posible respuesta. */
	if (argv[3][0] == 't' || argv[3][0] == 'd')
	{
		/* Asociar la dirección al socket. */
		/*int bind_result = bind(socket_d, result->ai_addr, result->ai_addrlen);
		if (bind_result == -1)
		{
			perror("Error: bind()");
			exit(EXIT_FAILURE);
		}*/
	
		/* Estructura para almacenar la dirección de un posible cliente. */
		struct sockaddr_storage client_addr;
		socklen_t client_addrlen = sizeof(client_addr);
		
		char buffer[BUFFER_SIZE + 1];
		
		/* Recibir la respuesta. */
		ssize_t recv_result = recvfrom(socket_d, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_addr, &client_addrlen);
		if (recv_result == -1)
		{
			perror("Error: recvfrom()\n");
			exit(EXIT_FAILURE);
		}
		
		buffer[recv_result] = '\0';
		
		printf("Respuesta: %s\n", buffer);
	}
	
	exit(EXIT_SUCCESS);
}