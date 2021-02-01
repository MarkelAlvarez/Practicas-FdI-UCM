#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//Estado del bus
#define EN_RUTA 0		// autobús en ruta
#define EN_PARADA 1		// autobús en la parada
#define N_PARADAS 5		// número de paradas de la ruta
#define MAX_USUARIOS 40 // capacidad del autobús
#define USUARIOS 4		// numero de usuarios
// estado inicial
int estado = EN_RUTA;  // = 0, = 1 para EN_PARADA
int parada_actual = 0; // parada en la que se encuentra el autobus
int n_ocupantes = 0;   // ocupantes que tiene el autobús
//Arrays dinamicos para poder ajustar el tamaño segun los parametros de entrada
int *esperando_parada; //= {0,0,...0}; // personas que desean subir en cada parada
int *esperando_bajar;  //= {0,0,...0}; // personas que desean bajar en cada parada
//Mutex
pthread_mutex_t mutex;
//Variables de condicion
pthread_cond_t en_parada;
pthread_cond_t busListo;
//Threads
pthread_t bus;
pthread_t *usuarios; //[USUARIOS]; //Array dinamico para poder ajustar el tamaño segun los parametros de entrada

/*/* Ajustar el estado y bloquear al autobús hasta que no haya pasajeros que
quieran bajar y/o subir la parada actual. Después se pone en marcha */
void Autobus_En_Parada()
{
	// Se bloquea el mutex, cambio de estado, llegada a la parada, gestion de condiciones, se desbloquea el mutex
	pthread_mutex_lock(&mutex);
	estado = EN_PARADA;
	printf("Autobus en parada [%d].\n", parada_actual);

	// Espera hasta que todos los usuarios de la parada se suban y los que tengan que bajar se hayan bajado
	while (esperando_bajar[parada_actual] > 0 || (esperando_parada[parada_actual] > 0) && n_ocupantes < MAX_USUARIOS)
	{
		// Avisa a todos los usuarios que esta parado en parada_actual
		pthread_cond_broadcast(&en_parada);
		pthread_cond_wait(&busListo, &mutex);
	}

	printf("No hay más usuarios esperando.\n");
	pthread_mutex_unlock(&mutex);
}

/* Establecer un retardo que simule el trayecto y actualizar numero de parada */
void Conducir_Hasta_Siguiente_Parada()
{
	// Conduce
	printf("\n---------- Autobus en ruta ----------\n");
	sleep(random() % 2);

	// Se bloquea el mutex, cambio de estado, llegada a la parada, se desbloquea el mutex
	pthread_mutex_lock(&mutex);
	estado = EN_RUTA;

	// Llega a la siguiente parada
	parada_actual = (parada_actual + 1) % N_PARADAS;
	printf("Autobus acaba de llegar a la parada [%d].\n", parada_actual);
	pthread_mutex_unlock(&mutex);
}

/* El usuario indicará que quiere subir en la parada ’origen’, esperará a que
	el autobús se pare en dicha parada y subirá. El id_usuario puede utilizarse para
	proporcionar información de depuración */
void Subir_Autobus(int id_usuario, int origen)
{
	// Se bloquea el mutex, gestion de condiciones y pasajeros, se desbloquea el mutex
	pthread_mutex_lock(&mutex);
	esperando_parada[origen]++;
	printf("Usuario [%d] esperando en la parada [%d] para SUBIR.\n", id_usuario, origen);

	while (n_ocupantes < MAX_USUARIOS && estado == EN_PARADA && parada_actual != origen)
	{
		pthread_cond_wait(&en_parada, &mutex);
	}

	printf("Usuario [%d] en la parada [%d] acaba de SUBIR al autobus.\n", id_usuario, origen);
	n_ocupantes++;
	esperando_parada[origen]--;

	if (esperando_bajar[origen] == 0 && esperando_parada[origen] == 0)
	{
		pthread_cond_signal(&busListo);
	}

	pthread_mutex_unlock(&mutex);
}

/* El usuario indicará que quiere bajar en la parada ’destino’, esperará a que
	el autobús se pare en dicha parada y bajará. El id_usuario puede utilizarse para
	proporcionar información de depuración */
void Bajar_Autobus(int id_usuario, int destino)
{
	//Se bloquea el mutex, gestion de condiciones y pasajeros, se desbloquea el mutex
	pthread_mutex_lock(&mutex);
	esperando_bajar[destino]++;
	printf("Usuario [%d] esperando para BAJAR en la parada [%d].\n", id_usuario, destino);

	while (estado == EN_PARADA && parada_actual != destino)
	{
		pthread_cond_wait(&en_parada, &mutex);
	}

	printf("Usuario [%d] en la parada [%d] acaba de BAJAR del autobus.\n", id_usuario, destino);
	n_ocupantes--;
	esperando_bajar[destino]--;

	if (esperando_bajar[destino] == 0 && esperando_parada[destino] == 0)
	{
		pthread_cond_signal(&busListo);
	}

	pthread_mutex_unlock(&mutex);
}

// Otras definiciones globales (comunicación y sincronización)
void Usuario(int id_usuario, int origen, int destino)
{
	Subir_Autobus(id_usuario, origen); //Esperar a que el autobus esté en parada origen para subir
	Bajar_Autobus(id_usuario, destino);			//Bajarme en estación destino
}

void *thread_autobus(void *args)
{
	while (1)
	{
		Autobus_En_Parada();			   //esperar a que los viajeros suban y bajen
		Conducir_Hasta_Siguiente_Parada(); //conducir hasta siguiente parada
	}
}

void *thread_usuario(void *arg)
{
	int a, b, id_usuario = (int)arg; // obtener el id del usario

	while (1)
	{
		a = rand() % N_PARADAS;

		do
		{
			b = rand() % N_PARADAS;
		} while (a == b);
		printf("--- El usuario [%d] ha decidido hacer la ruta [%d] -> [%d].\n", id_usuario, a, b);

		Usuario(id_usuario, a, b);
	}
}

int main(int argc, char *argv[])
{
	int i;

	/*if (argc < 4)
	{
		fprintf(stderr, "%s", "./simulator capacidad_autobus num_usuarios num_paradas\n");
		exit(EXIT_FAILURE);
	}

	MAX_USUARIOS = strtol(argv[1], NULL, 10);
	USUARIOS = strtol(argv[2], NULL, 10);
	N_PARADAS = strtol(argv[3], NULL, 10);

	printf("MaxUsuarios %d\n", MAX_USUARIOS);
	printf("Usuarios %d\n", USUARIOS);
	printf("NParadas %d\n", N_PARADAS);*/

	// Debug
	if (USUARIOS > MAX_USUARIOS) 
	{
		fprintf(stderr, "%s", "No me pongas mas usuarios que el máximo de usuarios por favor\n");
		exit(EXIT_FAILURE);
	}

	// Creacion de arrays
	usuarios = malloc(USUARIOS * sizeof(int));
	esperando_parada = malloc(N_PARADAS * sizeof(int));
	esperando_bajar = malloc(N_PARADAS * sizeof(int));

	// Crear el thread Autobus
	pthread_create(&bus, NULL, thread_autobus, NULL); //Hilo

	// Inicializaciones (se podria sacar a metodo)
	pthread_mutex_init(&mutex, NULL);		//Mutex
	pthread_cond_init(&busListo, NULL); 	//Condicion de arranque del bus
	pthread_cond_init(&en_parada, NULL);	//Condicion de parada del bus

	for (i = 0; i < USUARIOS; i++) //Crear thread para el usuario i
	{
		pthread_create(&usuarios[i], NULL, thread_usuario, (void *)i);
	}

	pthread_join(bus, NULL);

	// Esperar terminación de los hilos
	for (i = 0; i < USUARIOS; i++)
	{
		pthread_join(usuarios[i], NULL);
	}

	return 0;
}