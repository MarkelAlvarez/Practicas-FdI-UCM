#include <stdio.h>
#include "44b.h"
#include "leds.h"
#include "utils.h"
#include "D8Led.h"
#include "intcontroller.h"
#include "timer.h"
#include "gpio.h"
#include "keyboard.h"

#define N 4

/* Variables para la gestión de la ISR del teclado
 * 
 * Keybuffer: puntero que apuntará al buffer en el que la ISR del teclado debe
 *            almacenar las teclas pulsadas
 * keyCount: variable en el que la ISR del teclado almacenará el número de teclas pulsadas
 */
volatile static char *keyBuffer = NULL;
volatile static int keyCount = 0;

/* Variables para la gestion de la ISR del timer
 * 
 * tmrbuffer: puntero que apuntará al buffer que contendrá los dígitos que la ISR del
 *            timer debe mostrar en el display de 8 segmentos
 * tmrBuffSize: usado por printD8Led para indicar el tamaño del buffer a mostrar
 */
volatile static char *tmrBuffer = NULL;
volatile static int tmrBuffSize = 0;

//Variables globales para la gestión del juego
static char passwd[N];  //Buffer para guardar la clave inicial
static char guess[N];   //Buffer para guardar la segunda clave

enum state {
	INIT = 0,     //Init:       Inicio del juego
	SPWD = 1,     //Show Pwd:   Mostrar password
	DOGUESS = 2,  //Do guess:   Adivinar contraseña
	SGUESS = 3,   //Show guess: Mostrar el intento
	GOVER = 4     //Game Over:  Mostrar el resultado
};
enum state gstate; //estado/fase del juego 

//COMPLETAR: Declaración adelantada de las ISRs de timer y teclado (las marca como ISRs)


// Función que va guardando las teclas pulsadas
static void push_buffer(char *buffer, int key)
{
	int i;
	for (i=0; i < N-1; i++)
		buffer[i] = buffer[i+1];
	buffer[N-1] = (char) key;
}

void timer_ISR(void)
{
	static int pos = 0; //contador para llevar la cuenta del dígito del buffer que toca mostrar

    //COMPLETAR: Visualizar el dígito en la posición pos del buffer tmrBuffer en el display

	// Si es el último dígito: 
	//      Poner pos a cero, 
	//      Parar timer
	//      Dar tmrBuffer valor NULL

	// Si no, se apunta al siguiente dígito a visualizar (pos)

	// COMPLETAR: Finalizar correctamente la ISR
}

void printD8Led(char *buffer, int size)
{
	//Esta rutina prepara el buffer que debe usar timer_ISR (tmrBuffer)
	tmrBuffer = buffer;
	tmrBuffSize = size;
	
	//COMPLETAR: Arrancar el TIMER0 

	//COMPLETAR: Esperar a que timer_ISR termine (tmrBuffer)
}

void keyboard_ISR(void)
{
	int key;

	/* Eliminar rebotes de presión */
	Delay(200);

	/* Escaneo de tecla */
	// COMPLETAR


	if (key != -1) {
		//COMPLETAR:
		//Si la tecla pulsada es F deshabilitar interrupciones por teclado y 
		//poner keyBuffer a NULL

		// Si la tecla no es F guardamos la tecla pulsada en el buffer apuntado
		// por keybuffer mediante la llamada a la rutina push_buffer
		
		// Actualizamos la cuenta del número de teclas pulsadas

		/* Esperar a que la tecla se suelte, consultando el registro de datos rPDATG */		
		while (!(rPDATG & 0x02));
	}

	/* Eliminar rebotes de depresiÃ³n */
	Delay(200);

	//COMPLETAR: Finalizar correctamente la ISR

}

int read_kbd(char *buffer)
{
	//Esta rutina prepara el buffer en el que keyboard_ISR almacenará las teclas 
	//pulsadas (keyBuffer) y pone a 0 el contador de teclas pulsadas
	keyBuffer = buffer;
	keyCount = 0;

	//COMPLETAR: Habilitar interrupciones por teclado

	//COMPLETAR: Esperar a que keyboard_ISR indique que se ha terminado de
	//introducir la clave (keyBuffer)

	//COMPLETAR: Devolver número de teclas pulsadas
}

static int show_result()
{
	int error = 0;
	int i = 0;
	char buffer[2] = {0};

	// COMPLETAR: poner error a 1 si las contraseñas son distintas

	// COMPLETAR
	// Hay que visualizar el resultado durante 2s.
	// Si se ha acertado tenemos que mostrar una A y si no una E
	// Como en printD8Led haremos que la ISR del timer muestre un buffer con dos
	// caracteres A o dos caracteres E (eso durará 2s)
	
	// COMPLETAR: esperar a que la ISR del timer indique que se ha terminado

	// COMPLETAR: Devolver el valor de error para indicar si se ha acertado o no
}

int setup(void)
{

	D8Led_init();

	/* COMPLETAR: Configuración del timer0 para interrumpir cada segundo */


	/***************************/
	/* COMPLETAR: Port G-configuración para generación de interrupciones externas
	 *         por teclado
	 **/


	/********************************************************************/

	// COMPLETAR: Registramos las ISRs


	/* Configuración del controlador de interrupciones*/


	ic_init();

	 /* Habilitamos la línea IRQ, en modo vectorizado y registramos una ISR para
		 * la línea IRQ
		 * Configuramos el timer 0 en modo IRQ y habilitamos esta línea
		 * Configuramos la línea EINT1 en modo IRQ y la habilitamos
		 */

	/***************************************************/

	Delay(0);

	/* Inicio del juego */
	gstate = INIT;
	D8Led_digit(12);

	return 0;
}


int loop(void)
{
	int count; //número de teclas pulsadas
	int error;

	//Máquina de estados

	switch (gstate) {
		case INIT:
			do {
				//COMPLETAR:
    			//Visualizar una C en el display
     			//Llamar a la rutina read_kbd para guardar los 4 dígitos en el buffer passwd
     			//Esta rutina devuelve el número de teclas pulsadas.
				//Dibujar una E en el display si el número de teclas pulsadas es menor que 4
			} while (/*permanecer en el while mientras se hayan pulsado menos de 4 teclas*/);

			//COMPLETAR: Pasar al estado siguiente

			break;

		case SPWD:

			// COMPLETAR:
			// Visualizar en el display los 4 dígitos del buffer passwd, para
			// ello llamar a la rutina printD8Led
			Delay(10000);
			//COMPLETAR: Pasar al estado siguiente

			break;

		case DOGUESS:
			Delay(10000);

			do {
				//COMPLETAR:
				//Visualizar en el display una F
				//Llamar a la rutina read_kbd para guardar los 4 dígitos en el buffer guess
				//Esta rutina devuelve el número de teclas pulsadas.
				//Dibujar una E en el display si el número de teclas pulsadas es menor que 4
			} while (/*permanecer en el while mientras se hayan pulsado menos de 4 teclas*/);

			//COMPLETAR: Pasar al estado siguiente

			break;

		case SGUESS:
			//COMPLETAR:
			//Visualizar en el display los 4 dígitos del buffer guess, 
			//para ello llamar a la rutina printD8Led
			Delay(10000);
			//COMPLETAR: Pasar al estado siguiente

			break;

		case GOVER:
			//COMPLETAR:
			//Mostrar el mensaje de acierto o error con show_result()
			Delay(10000);
			//Si he acertado el estado siguiente es INIT sino DOGUESS

			break;
	}
	return 0;
}

int main(void)
{
	setup();

	while (1) {
		loop();
	}
}
