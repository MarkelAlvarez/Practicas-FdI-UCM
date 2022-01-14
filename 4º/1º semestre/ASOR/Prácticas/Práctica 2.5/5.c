#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define BUFFER_SIZE 2
#define MESSAGE_SIZE 128

void gestionarMensajes(int socketd);

int main(int argc, char **argv)
{
	/* Comprobar argumento. */
	if (argc != 3)
	{
		printf("Uso: %s <host> <puerto>\n", argv[0]);
		
		exit(EXIT_FAILURE);
	}

	/* Preparar las estructuras. */
	struct addrinfo hints;
	struct addrinfo *result;

	/* Preparar y establecer los hints. */
	memset(&hints, 0, sizeof(struct addrinfo));
	
	hints.ai_family 	= AF_UNSPEC;
	hints.ai_socktype 	= SOCK_DGRAM;
	hints.ai_flags 		= AI_PASSIVE;
	hints.ai_protocol 	= 0;
	hints.ai_canonname 	= NULL;
	hints.ai_addr 		= NULL;
	hints.ai_next 		= NULL;
	
	/* Obtener una dirección de socket a partir del host y el servicio. */
	int s = getaddrinfo(argv[1], argv[2], &hints, &result);
	
	/* Comprobar errores. */
	if (s != 0)
	{
		printf("Error getaddrinfo(): %s\n", gai_strerror(s));
		
		exit(EXIT_FAILURE);
	}
	
	/* getaddrinfo() devuelve una lista de estructuras de dirección. */
	/* Crear el socket. */
	int socketd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (socketd == -1)
	{
		printf("Error: no pudo abrirse el socket (socket()).\n");

		exit(EXIT_FAILURE);
	}
	
	/* Asociar el socket a la dirección. */
	if (bind(socketd, result->ai_addr, result->ai_addrlen) == -1)
	{
		printf("Error: no pudo asociarse el socket a la dirección (bind()).\n");

		exit(EXIT_FAILURE);
	}
	
	freeaddrinfo(result);
	
	printf("Escuchando...\n");
	
	for (int i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		switch(pid)
		{
			case -1:
				return 1;
			case 0:
				gestionarMensajes(socketd);
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

void gestionarMensajes(int socketd)
{
	/* Estructura para almacenar la dirección de un posible cliente. */
	struct sockaddr_storage client_addr;
	socklen_t client_addrlen = sizeof(client_addr);
	
	/* Estructuras auxiliares para la recepcíon, el tiempo y la respuesta. */
	/* Cliente. */
	char host[NI_MAXHOST];
	char service[NI_MAXSERV];
	
	/* Buffer de recepción. */
	char buffer[BUFFER_SIZE + 1];
	
	/* Tiempo y respuesta. */
	ssize_t l;
	time_t t;
	size_t time_bytes;
	struct tm *tm;
	char msg[MESSAGE_SIZE + 1];
	
	/* Bucle para la recepción de datos. */
	while (1)
	{
		/* Recibir datos desde el cliente. */
		/* Como la dirección está vacía, recibe desde cualquiera. */
		l = recvfrom(socketd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_addr, &client_addrlen);
		buffer[l - 1] = '\0';
		
		/* Convertir la dirección de socket a un host y un servicio. */
		getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
		printf("Recibidos %ld bytes desde host %s y servicio %s: %s\n", l, host, service, buffer);
		
		/* Preparar la respuesta. */
		t = time(NULL);
		tm = localtime(&t);
		
		/* Comprobar comando. */
		if (buffer[0] == 't')
		{
			time_bytes = strftime(msg, MESSAGE_SIZE, "%T", tm);
			msg[time_bytes] = '\n';
			msg[time_bytes + 1] = '\0';
			
			if (sendto(socketd, msg, time_bytes + 2, 0, (struct sockaddr *) &client_addr, client_addrlen) == -1)
			{
				printf("sendto()\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (buffer[0] == 'd')
		{
			time_bytes = strftime(msg, MESSAGE_SIZE, "%F", tm);
			msg[time_bytes] = '\n';
			msg[time_bytes + 1] = '\0';
			
			if (sendto(socketd, msg, time_bytes + 2, 0, (struct sockaddr *) &client_addr, client_addrlen) == -1)
			{
				printf("sendto()\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (buffer[0] == 'q')
		{
			printf("Saliendo...\n");
			
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Comando no soportado: %s\n", buffer);
		}
	}
}