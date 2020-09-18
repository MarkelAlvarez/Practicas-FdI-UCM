#include <stdio.h>
#include "44b.h"
#include "leds.h"
#include "utils.h"
#include "D8Led.h"
#include "intcontroller.h"
#include "timer.h"
#include "gpio.h"
#include "keyboard.h"

#define N 4 //Tama�o del buffer tmrbuffer
#define M 128 //Tama�o del buffer readlineBuf que se pasa como par�metro a la rutina readline

/* Variables para la gesti�n de la ISR del teclado
 * 
 * Keybuffer: puntero que apuntar� al buffer en el que la ISR del teclado debe
 *            almacenar las teclas pulsadas
 * keyCount: variable en el que la ISR del teclado almacenar� el n�mero de teclas pulsadas
 */
volatile static char *keyBuffer = NULL;
volatile static int keyCount = 0;

/* Variables para la gestion de la ISR del timer
 * 
 * tmrbuffer: puntero que apuntar� al buffer que contendr� los d�gitos que la ISR del
 *            timer debe mostrar en el display de 8 segmentos
 * tmrBuffSize: usado por printD8Led para indicar el tama�o del buffer a mostrar
 */
volatile static char *tmrBuffer = NULL;
volatile static int tmrBuffSize = 0;

//Variables globales para la gesti�n del juego
static char passwd[N];  //Buffer para guardar la clave inicial
static char guess[N];   //Buffer para guardar la segunda clave
char readlineBuf[M];    //Buffer para guardar la linea le�da del puerto serie

//Configuraci�n de la uart
struct ulconf uconf = {
	.ired = OFF,
	.par  = ONE,
	.wordlen = EIGHT,
	.echo = ON,
	.baud    = 115200,
};

enum state {
	INIT = 0,     //Init:       Inicio del juego
	SPWD = 1,     //Show Pwd:   Mostrar password
	DOGUESS = 2,  //Do guess:   Adivinar contrase�a
	SGUESS = 3,   //Show guess: Mostrar el intento
	GOVER = 4     //Game Over:  Mostrar el resultado
};
enum state gstate; //estado/fase del juego 

//COMPLETAR: Declaraci�n adelantada de las ISRs de timer y teclado (las marca como ISRs)
// C�digo de la parte1


// Funci�n que va guardando las teclas pulsadas
static void push_buffer(char *buffer, int key)
{
	int i;
	for (i=0; i < N-1; i++)
		buffer[i] = buffer[i+1];
	buffer[N-1] = (char) key;
}

void timer_ISR(void)
{
	static int pos = 0; //contador para llevar la cuenta del d�gito del buffer que toca mostrar

    //COMPLETAR: Visualizar el d�gito en la posici�n pos del buffer tmrBuffer en el display

	// C�digo de la parte1
	
	// COMPLETAR: Finalizar correctamente la ISR
	
	// C�digo de la parte1
}

void printD8Led(char *buffer, int size)
{
	//Esta rutina prepara el buffer que debe usar timer_ISR (tmrBuffer)
	tmrBuffer = buffer;
	tmrBuffSize = size;
	
	//COMPLETAR: Arrancar el TIMER0 
	
	// C�digo de la parte1

	//COMPLETAR: Esperar a que timer_ISR termine (tmrBuffer)
	
	// C�digo de la parte1
}

void keyboard_ISR(void)
{
	int key;

	/* Eliminar rebotes de presi�n */
	Delay(200);

	/* Escaneo de tecla */
	// COMPLETAR

	// C�digo de la parte1

	if (key != -1) {
		//COMPLETAR:

		// C�digo de la parte1
		
		/* Esperar a que la tecla se suelte, consultando el registro de datos rPDATG */		
		while (!(rPDATG & 0x02));
	}

	/* Eliminar rebotes de depresi�n */
	Delay(200);

	//COMPLETAR: Finalizar correctamente la ISR

	// C�digo de la parte1
}

int read_kbd(char *buffer)
{
	//Esta rutina prepara el buffer en el que keyboard_ISR almacenar� las teclas 
	//pulsadas (keyBuffer) y pone a 0 el contador de teclas pulsadas
	keyBuffer = buffer;
	keyCount = 0;

	//COMPLETAR: Habilitar interrupciones por teclado

	// C�digo de la parte1
	
	//COMPLETAR: Esperar a que keyboard_ISR indique que se ha terminado de
	//introducir la clave (keyBuffer)

	// C�digo de la parte1
	
	//COMPLETAR: Devolver n�mero de teclas pulsadas
	
	// C�digo de la parte1
}

int readline(char *buffer, int size)
{
	int count = 0; //cuenta del n�mero de bytes leidos
	char c;        //variable para almacenar el car�cter le�do

	if (size == 0)
		return 0;

	// COMPLETAR: Leer caracteres de la uart0 y copiarlos al buffer
	// hasta que llenemos el buffer (size) o el car�cter le�do sea
	// un retorno de carro '\r'
	// Los caracteres se leen de uno en uno, utilizando la interfaz
	// del m�dulo uart, definida en el fichero uart.h

	return count;
}

static int show_result()
{
	int error = 0;
	int i = 0;
	char buffer[2] = {0};

	// COMPLETAR: poner error a 1 si las contrase�as son distintas

	// C�digo de la parte1
	
	// COMPLETAR
	
	// MODIFICAR el c�digo de la parte1 para que adem�s de mostrar A o E en el
	// display de 8 segmentos se env�e por el puerto serie uart0 la cadena "\nCorrecto\n"
	// o "\nError\n" utilizando el interfaz del puerto serie definido en uart.h
	
	// COMPLETAR: esperar a que la ISR del timer indique que se ha terminado

	// C�digo de la parte1
	
	// COMPLETAR: Devolver el valor de error para indicar si se ha acertado o no
	
	// C�digo de la parte1
}

int setup(void)
{

	D8Led_init();

	/* COMPLETAR: Configuraci�n del timer0 para interrumpir cada segundo */

	// C�digo de la parte1

	/********************************************************************/

	// COMPLETAR: Registramos las ISRs

	// C�digo de la parte1

	/* Configuraci�n del controlador de interrupciones*/
	ic_init();

	// C�digo de la parte1

	/***************************************************/

	/***************************************************/
	//COMPLETAR: Configuraci�n de la uart0
	
		/* Hay que:
		 * 1. inicializar el m�dulo
		 * 2. Configurar el modo linea de la uart0 usando la variable global uconf
		 * 3. Configurar el modo de recepci�n (POLL o INT) de la uart0
		 * 4. Configurar el modo de transmisi�n (POLL o INT) de la uart0
		 */

	/***************************************************/

	Delay(0);

	/* Inicio del juego */
	gstate = INIT;
	D8Led_digit(12);

	return 0;
}

static char ascii2digit(char c)
{
	char d = -1;

	if ((c >= '0') && (c <= '9'))
		d = c - '0';
	else if ((c >= 'a') && (c <= 'f'))
		d = c - 'a' + 10;
	else if ((c >= 'A') && (c <= 'F'))
		d = c - 'A' + 10;

	return d;
}


int loop(void)
{
	int count; //n�mero de teclas pulsadas
	int error;

	//M�quina de estados

	switch (gstate) {
		case INIT:
			do {
				//COMPLETAR:

				//Codigo de la parte 1
				
			} while (/*permanecer en el while mientras se hayan pulsado menos de 4 teclas*/);

			//COMPLETAR: Pasar al estado siguiente

		    //Codigo de la parte 1

			break;

		case SPWD:

			// COMPLETAR:
		    //Codigo de la parte 1
			
			Delay(10000);
			//COMPLETAR
		    //Codigo de la parte 1

			break;

		case DOGUESS:
			Delay(10000);
			do {
				//COMPLETAR:
				/* 
				 * 1. Mandar por el puerto serie uart0 la cadena "Introduzca passwd: "
				 *    usando el interfaz definido en uart.h
				 *
				 * 2. Mostrar una F en el display
				 *
				 * 3. Llamar a la rutina readline para leer una l�nea del puerto
				 *    serie en el buffer readlineBuf, almacenando en count el
				 *    valor devuelto (n�mero de caracteres le�dos)
				 *
				 * 4. Si el �ltimo caracter le�do es un '\r' decrementamos count
				 *    para no tenerlo en cuenta
				 *
				 * 5. Si count es menor de 4 la clave no es v�lida, mostramos
				 *    una E (digito 14) en el display de 8 segmentos y esperamos
				 *    1 segundo con Delay.
				 */
			} while (/* Mientras leamos menos de 4 caracteres*/);

			/* COMPLETAR: debemos copiar los 4 �ltimos caracteres de readline en
			 * el buffer guess, haciendo la conversi�n de ascii-hexadecimal a valor 
			 * decimal. Para ello podemos utilizar la funci�n ascii2digit
			 * definida m�s arriba.
			 */

			//COMPLETAR: Pasar al estado siguiente
			//C�digo de la parte1

			break;

		case SGUESS:
			//COMPLETAR:
			//C�digo de la parte1
			
			Delay(10000);
			//COMPLETAR: Pasar al estado siguiente
			//C�digo de la parte1
			break;

		case GOVER:
			//COMPLETAR:
			//C�digo de la parte1
			Delay(10000);
			//COMPLETAR:
			//C�digo de la parte1

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
