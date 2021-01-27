#define N_PARADAS 5 // número de paradas de la ruta
#define EN_RUTA 0   // autobús en ruta
#define EN_PARADA 1 // autobús en la parada
#define MAX_USUARIOS 40 // capacidad del autobús
#define USUARIOS 4 // numero de usuarios
int estado = EN_RUTA; // estado inicial
int parada_actual = 0; // parada en la que se encuentra el autobus
int n_ocupantes = 0; // ocupantes que tiene el autobús

/* personas que desean subir en cada parada */
int esperando_parada[N_PARADAS]; //= {0,0,...0};

/* personas que desean bajar en cada parada */
int esperando_bajar[N_PARADAS]; //= {0,0,...0};

/** Otras definiciones globales (comunicación y sincronización) **/
/** COMPLETAR CON DEFINICIÓN DE VARIABLES NECESARIAS ***/






/* FUNCIONES A IMPLEMENTAR */

void Autobus_En_Parada() {
/* Ajustar el estado y bloquear al autobús hasta que no haya pasajeros que
quieran bajar y/o subir la parada actual. Después se pone en marcha */


/* COMPLETAR */


}

void Conducir_Hasta_Siguiente_Parada() {
/* Establecer un Retardo que simule el trayecto y actualizar numero de parada */

/* COMPLETAR */


}


void Subir_Autobus(int id_usuario, int origen) {
/* El usuario indicará que quiere subir en la parada ’origen’, esperará a que
el autobús se pare en dicha parada y subirá. El id_usuario puede utilizarse para
proporcionar información de depuración */

/* COMPLETAR */


}

void Bajar_Autobus(int id_usuario, int destino){
/* El usuario indicará que quiere bajar en la parada ’destino’, esperará a que
el autobús se pare en dicha parada y bajará. El id_usuario puede utilizarse para
proporcionar información de depuración */


/* COMPLETAR */


}