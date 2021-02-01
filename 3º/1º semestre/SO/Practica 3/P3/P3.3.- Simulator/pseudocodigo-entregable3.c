#define N_PARADAS 5		// número de paradas de la ruta
#define EN_RUTA 0		// autobús en ruta
#define EN_PARADA 1		// autobús en la parada
#define MAX_USUARIOS 40 // capacidad del autobús
#define USUARIOS 4		// numero de usuarios
int estado = EN_RUTA;	// estado inicial
int parada_actual = 0;	// parada en la que se encuentra el autobus
int n_ocupantes = 0;	// ocupantes que tiene el autobús

/* personas que desean subir en cada parada */
//int esperando_parada[N_PARADAS]; //= {0,0,...0};
int *esperando_parada;

/* personas que desean bajar en cada parada */
//int esperando_bajar[N_PARADAS]; //= {0,0,...0};
int *esperando_bajar;

/** Otras definiciones globales (comunicación y sincronización) **/
pthread_mutex_t mutex;

pthread_cond_t en_parada[parada_actual];
pthread_cond_t autobus;

/* FUNCIONES A IMPLEMENTAR */
/* Ajustar el estado y bloquear al autobús hasta que no haya pasajeros que
quieran bajar y/o subir la parada actual. Después se pone en marcha */
void Autobus_En_Parada()
{
	pthread_mutex_lock(&mutex);
	printf("Autobus en parada [%d].\n", parada_actual);

	while (esperando_parada[parada_actual] > 0 || esperando_bajar[parada_actual] > 0)
	{
		pthread_cond_wait(&autobus, &mutex);
	}

	pthread_mutex_unlock(&mutex);
}

/* Establecer un Retardo que simule el trayecto y actualizar numero de parada */
void Conducir_Hasta_Siguiente_Parada()
{
	pthread_mutex_lock(&mutex);
	estado = EN_RUTA; //COMIENZA A IR A LA SIGUIENTE PARADA
	printf("----------  Autobus en ruta  ----------\n");
	pthread_mutex_unlock(&mutex);

	sleep(rand() % 10); //DORMIMOS PARA SIMULAR EL TRAYECTO

	pthread_mutex_lock(&mutex);
	parada_actual = ++parada_actual % N_PARADAS;
	estado = EN_PARADA;
	pthread_cond_broadcast(&en_parada[parada_actual]);
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
		pthread_cond_signal(&autobus);
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
		pthread_cond_signal(&autobus);
	}

	pthread_mutex_unlock(&mutex);
}