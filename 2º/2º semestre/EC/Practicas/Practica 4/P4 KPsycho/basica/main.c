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

/* Variables para la gestiï¿½n de la ISR del teclado
 * 
 * Keybuffer: puntero que apuntarï¿½ al buffer en el que la ISR del teclado debe
 *            almacenar las teclas pulsadas
 * keyCount: variable en el que la ISR del teclado almacenarï¿½ el nï¿½mero de teclas pulsadas
 */
volatile static char *keyBuffer = NULL;
volatile static int keyCount = 0;

/* Variables para la gestion de la ISR del timer
 * 
 * tmrbuffer: puntero que apuntarï¿½ al buffer que contendrï¿½ los dï¿½gitos que la ISR del
 *            timer debe mostrar en el display de 8 segmentos
 * tmrBuffSize: usado por printD8Led para indicar el tamaï¿½o del buffer a mostrar
 */
volatile static char *tmrBuffer = NULL;
volatile static int tmrBuffSize = 0;

//Variables globales para la gestiï¿½n del juego
static char passwd[N];  //Buffer para guardar la clave inicial
static char guess[N];   //Buffer para guardar la segunda clave

enum state {
	INIT = 0,     //Init:       Inicio del juego
	SPWD = 1,     //Show Pwd:   Mostrar password
	DOGUESS = 2,  //Do guess:   Adivinar contraseï¿½a
	SGUESS = 3,   //Show guess: Mostrar el intento
	GOVER = 4     //Game Over:  Mostrar el resultado
};
enum state gstate; //estado/fase del juego 

//COMPLETAR: Declaraciï¿½n adelantada de las ISRs de timer y teclado (las marca como ISRs)

void timer0_ISR(void) __attribute__ ((interrupt ("IRQ")));
void keyboard_ISR(void) __attribute__ ((interrupt ("IRQ")));

// Funciï¿½n que va guardando las teclas pulsadas
static void push_buffer(char *buffer, int key) {
	int i;
	for (i=0; i < N-1; i++)
		buffer[i] = buffer[i+1];
	buffer[N-1] = (char) key;
}

void timer0_ISR(void) {
	static int pos = 0; //contador para llevar la cuenta del dï¿½gito del buffer que toca mostrar

    //COMPLETAR: Visualizar el dï¿½gito en la posiciï¿½n pos del buffer tmrBuffer en el display
	D8Led_digit(*(tmrBuffer + pos));

	// Si es el ï¿½ltimo dï¿½gito: 
	//      Poner pos a cero, 
	//      Parar timer
	//      Dar tmrBuffer valor NULL

	// Si no, se apunta al siguiente dï¿½gito a visualizar (pos)

	if(pos == tmrBuffSize - 1){

		pos = 0;
		tmr_stop(TIMER0);
		tmrBuffer = NULL;

	} else{

		++pos;

	}

	// COMPLETAR: Finalizar correctamente la ISR

	ic_cleanflag(INT_TIMER0);
}

void printD8Led(char *buffer, int size) {
	//Esta rutina prepara el buffer que debe usar timer_ISR (tmrBuffer)
	tmrBuffer = buffer;
	tmrBuffSize = size;
	
	//COMPLETAR: Arrancar el TIMER0 
	tmr_start(TIMER0);

	//COMPLETAR: Esperar a que timer_ISR termine (tmrBuffer)
	while(tmrBuffer != NULL);

}

void keyboard_ISR(void) {

	int key;

	D8Led_init();

	/* Eliminar rebotes de presiï¿½n */
	Delay(200);

	/* Escaneo de tecla */
	// COMPLETAR

	key = kb_scan();
	D8Led_digit(key);

	if (key != -1) {
		//COMPLETAR:
		//Si la tecla pulsada es F deshabilitar interrupciones por teclado y 
		//poner keyBuffer a NULL

		// Si la tecla no es F guardamos la tecla pulsada en el buffer apuntado
		// por keybuffer mediante la llamada a la rutina push_buffer
		
		switch(key){

			case 0xF:
				ic_disable(INT_EINT1);
				keyBuffer = NULL;
				break;

			default:
				push_buffer(keyBuffer, key);
				break;

		}

		// Actualizamos la cuenta del nï¿½mero de teclas pulsadas
		keyCount++;

		/* Esperar a que la tecla se suelte, consultando el registro de datos rPDATG */		
		while (!(rPDATG & 0x02));
		
	}

	/* Eliminar rebotes de depresiÃ³n */
	Delay(200);

	//COMPLETAR: Finalizar correctamente la ISR
	ic_cleanflag(INT_EINT1);

}

int read_kbd(char *buffer) {
	//Esta rutina prepara el buffer en el que keyboard_ISR almacenarï¿½ las teclas 
	//pulsadas (keyBuffer) y pone a 0 el contador de teclas pulsadas
	keyBuffer = buffer;
	keyCount = 0;

	//COMPLETAR: Habilitar interrupciones por teclado
	ic_enable(INT_EINT1);

	//COMPLETAR: Esperar a que keyboard_ISR indique que se ha terminado de
	//introducir la clave (keyBuffer)
	while(keyBuffer != NULL);

	//COMPLETAR: Devolver nï¿½mero de teclas pulsadas
	return keyCount;

}

static int show_result() {

	int error = 0;
	int i = 0;
	char buffer[2] = {0};

	// COMPLETAR: poner error a 1 si las contraseï¿½as son distintas
	while(i < N){

		if (passwd[i] != guess[i]){

			error = 1;
			break;

		}

		++i;

	}

	// COMPLETAR
	// Hay que visualizar el resultado durante 2s.
	// Si se ha acertado tenemos que mostrar una A y si no una E
	// Como en printD8Led haremos que la ISR del timer muestre un buffer con dos
	// caracteres A o dos caracteres E (eso durarï¿½ 2s)

	if(!error)
		D8Led_digit(0xA);
	else
		D8Led_digit(0xE);
	
	Delay(2000);
	
	// COMPLETAR: esperar a que la ISR del timer indique que se ha terminado
    while(tmrBuffer != NULL); 

	// COMPLETAR: Devolver el valor de error para indicar si se ha acertado o no
	return error;

}

int setup(void) {

	D8Led_init();

	/* COMPLETAR: Configuraciï¿½n del timer0 para interrumpir cada segundo */

	tmr_set_prescaler(TIMER0, 255);
	tmr_set_divider(TIMER0, D1_8);
	tmr_set_count(TIMER0, 31250, 15625);
	tmr_update(TIMER0);
	tmr_set_mode(TIMER0, RELOAD);
	tmr_stop(TIMER0);

	/***************************/
	/* COMPLETAR: Port G-configuraciï¿½n para generaciï¿½n de interrupciones externas
	 *         por teclado
	 **/

	portG_conf(1, EINT);
	portG_conf_pup(1, ENABLE);
	portG_eint_trig(1, FALLING);

	/********************************************************************/	
	// COMPLETAR: Registramos las ISRs
	pISR_TIMER0   = (unsigned) timer0_ISR;
	pISR_EINT1    = (unsigned) keyboard_ISR;

	/* Configuraciï¿½n del controlador de interrupciones*/

	ic_init();
	ic_conf_irq(ENABLE, VEC);
	ic_conf_fiq(DISABLE);
	ic_conf_line(INT_TIMER0, IRQ);
	ic_conf_line(INT_EINT1, IRQ);
	ic_enable(INT_TIMER0);
	ic_enable(INT_EINT1);

	 /* Habilitamos la lï¿½nea IRQ, en modo vectorizado y registramos una ISR para
		 * la lï¿½nea IRQ
		 * Configuramos el timer 0 en modo IRQ y habilitamos esta lï¿½nea
		 * Configuramos la lï¿½nea EINT1 en modo IRQ y la habilitamos
		 */

	/***************************************************/

	Delay(0);

	/* Inicio del juego */
	gstate = INIT;
	D8Led_digit(0xC);

	return 0;
}


int loop(void)
{
	int count; //nï¿½mero de teclas pulsadas
	int error;

	//Mï¿½quina de estados

	switch (gstate) {

		case INIT:
			do {
				//COMPLETAR:
    			//Visualizar una C en el display
     			//Llamar a la rutina read_kbd para guardar los 4 dï¿½gitos en el buffer passwd
     			//Esta rutina devuelve el nï¿½mero de teclas pulsadas.
				//Dibujar una E en el display si el nï¿½mero de teclas pulsadas es menor que 4
				/*permanecer en el while mientras se hayan pulsado menos de 4 teclas*/

				D8Led_digit(0xC);
				count = read_kbd(passwd);
				if(count < N){
					D8Led_digit(0xE);
					Delay(10000);
				}

			} while (count < N);

			//COMPLETAR: Pasar al estado siguiente
			gstate = SPWD;

			break;

		case SPWD:

			// COMPLETAR:
			// Visualizar en el display los 4 dï¿½gitos del buffer passwd, para
			// ello llamar a la rutina printD8Led

			printD8Led(passwd, N);
			Delay(10000);

			//COMPLETAR: Pasar al estado siguiente
			gstate = DOGUESS;

			break;

		case DOGUESS:

			Delay(10000);

			do {
				//COMPLETAR:
				//Visualizar en el display una F
				//Llamar a la rutina read_kbd para guardar los 4 dï¿½gitos en el buffer guess
				//Esta rutina devuelve el nï¿½mero de teclas pulsadas.
				//Dibujar una E en el display si el nï¿½mero de teclas pulsadas es menor que 4
				/*permanecer en el while mientras se hayan pulsado menos de 4 teclas*/

				D8Led_digit(0xF);
				count = read_kbd(guess);
				if(count < N){
					D8Led_digit(0xE);
					Delay(1000);
				}

			} while (count < N);

			//COMPLETAR: Pasar al estado siguiente
            gstate = SGUESS;
            
			break;

		case SGUESS:
			//COMPLETAR:
			//Visualizar en el display los 4 dï¿½gitos del buffer guess, 
			//para ello llamar a la rutina printD8Led

			printD8Led(guess, N);

			Delay(10000);
			//COMPLETAR: Pasar al estado siguiente
            gstate = GOVER;
            
			break;

		case GOVER:
			//COMPLETAR:
			//Mostrar el mensaje de acierto o error con show_result()

			error = show_result();
			Delay(10000);
			//Si he acertado el estado siguiente es INIT sino DOGUESS
            
			if(error)
				gstate = DOGUESS;
			else
				gstate = INIT;

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
