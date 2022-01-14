#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define SOCKET_BACKLOG 5
#define BUFFER_LEN 128

void gestionarMensajes(int socket_d);

int main(int argc, char **argv)
{
	/* Comprobar argumentos. */
	if (argc != 3)
	{
		printf("Uso: %s <host> <puerto>\n", argv[0]);
		
		exit(EXIT_FAILURE);
	}
	
	/* Preparar estructuras para obtener una dirección a partir del host. */
	struct addrinfo hints;
	struct addrinfo * result;
	
	memset(& hints, 0, sizeof(struct addrinfo));
	
	hints.ai_family 	= AF_UNSPEC;
	hints.ai_socktype 	= SOCK_STREAM;
	hints.ai_flags 		= AI_PASSIVE;
	hints.ai_protocol 	= 0;
	hints.ai_addrlen 	= 0;
	hints.ai_addr 		= NULL;
	hints.ai_canonname 	= NULL;
	hints.ai_next 		= NULL;
	
	/* Obtener una dirección a partir del host. */
	int info_result = getaddrinfo(argv[1], argv[2], &hints, &result);
	if (info_result != 0)
	{
		printf("Error: getaddrinfo(): %s\n", gai_strerror(info_result));
		exit(EXIT_FAILURE);
	}
	
	/* Crear el socket. */
	
	int socket_d = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (socket_d == -1)
	{
		perror("Error: socket()\n");
		exit(EXIT_FAILURE);
	}
	
	/* Asociar el socket a una dirección para que otros sockets puedan conectarse. */
	int bind_result = bind(socket_d, result->ai_addr, result->ai_addrlen);
	if (bind_result == -1)
	{
		perror("Error: bind()\n");
		exit(EXIT_FAILURE);
	}
	
	freeaddrinfo(result);
	
	for (int i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		switch(pid)
		{
			case -1:
				return 1;
			case 0:
				gestionarMensajes(socket_d);
				return 0;
			default:
				break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int hijo = wait(NULL);

		printf(" Termino HIJO: %d\n", hijo);
	}

	exit(EXIT_SUCCESS);
}

void gestionarMensajes(int socket_d)
{
	/* Colocar el socket en modo lectura. */
	int listen_result = listen(socket_d, SOCKET_BACKLOG);
	if (listen_result == -1)
	{
		perror("Error: listen()\n");
		exit(EXIT_FAILURE);
	}
	
	/* Aceptar nuevas conexiones. */
	struct sockaddr_storage client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int client_sd;
	int gni_result;
	char client_host[NI_MAXHOST];
	char client_service[NI_MAXSERV];
	ssize_t recv_len;
	ssize_t send_len;
	char client_buffer[BUFFER_LEN + 1];
	
	while (1)
	{
		client_sd = accept(socket_d, (struct sockaddr *) &client_addr, &client_addr_len);
		if (client_sd == -1)
		{
			perror("Error: accept()\n");
			exit(EXIT_FAILURE);
		}
		
		/* Obtener información del cliente. */
		gni_result = getnameinfo((struct sockaddr *) &client_addr, client_addr_len, client_host, NI_MAXHOST, client_service, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
		if (gni_result != 0)
		{
			printf("Error: getnameinfo(): %s\n", gai_strerror(gni_result));
			exit(EXIT_FAILURE);
		}
		
		printf("Conexión desde %s:%s\n", client_host, client_service);
		
		/* Recibir datos. */
		while (1)
		{
			recv_len = recv(client_sd, client_buffer, BUFFER_LEN, 0);
			if (recv_len == -1)
			{
				perror("Error: recv()\n");
				exit(EXIT_FAILURE);
			}
			else if (recv_len == 0)
			{
				/* Conexión cerrada. */
				break;
			}
			
			/* Responder. */
			send_len = send(client_sd, client_buffer, strlen(client_buffer), 0);
			if (send_len == -1)
			{
				perror("Error: send()\n");
				exit(EXIT_FAILURE);
			}
			
			/* Restablecer el buffer. */
			memset(client_buffer, 0, BUFFER_LEN);
		}
		
		printf("Conexión %s:%s terminada\n", client_host, client_service);
	}
}