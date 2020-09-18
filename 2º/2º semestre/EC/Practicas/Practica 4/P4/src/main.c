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

//Variables globales para la gesti�n del juego
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

static void push_buffer(char *buffer, int key)
{
	int i;

	for (i=0; i < N-1; i++)
	{
		buffer[i] = buffer[i+1];
	}
	buffer[N-1] = (char) key;
}

void timer0_ISR(void)
{
	static int pos = 0;

	D8Led_digit(*(tmrBuffer + pos));

	if(pos == tmrBuffSize - 1)
	{
		pos = 0;
		tmr_stop(TIMER0);
		tmrBuffer = NULL;
	}
	else
	{
		pos++;
	}

	ic_cleanflag(INT_TIMER0);
}

void printD8Led(char *buffer, int size)
{
	tmrBuffer = buffer;
	tmrBuffSize = size;
	
	tmr_start(TIMER0);

	while(tmrBuffer != NULL);
}

void keyboard_ISR(void)
{
	int key;

	D8Led_init();

	Delay(200);

	key = kb_scan();
	D8Led_digit(key);

	if (key != -1)
	{
		switch(key)
		{
			case 0xF:
				ic_disable(INT_EINT1);
				keyBuffer = NULL;
				break;
			default:
				push_buffer(keyBuffer, key);
				break;
		}
		keyCount++;
		while (!(rPDATG & 0x02));		
	}
	Delay(200);
	ic_cleanflag(INT_EINT1);

}

int read_kbd(char *buffer)
{
	keyBuffer = buffer;
	keyCount = 0;

	ic_enable(INT_EINT1);

	while(keyBuffer != NULL);

	return keyCount;
}

static int show_result()
{
	int error = 0, i = 0;
	char buffer[2] = {0};

	while(i < N)
	{
		if (passwd[i] != guess[i])
		{
			error = 1;
			break;
		}
		i++;
	}

	if(!error)
	{
		D8Led_digit(0xA);
	}
	else
	{
		D8Led_digit(0xE);
	}
	
	Delay(2000);
    while(tmrBuffer != NULL); 

	return error;
}

int setup(void)
{
	D8Led_init();

	tmr_set_prescaler(TIMER0, 255);
	tmr_set_divider(TIMER0, D1_8);
	tmr_set_count(TIMER0, 31250, 15625);
	tmr_update(TIMER0);
	tmr_set_mode(TIMER0, RELOAD);
	tmr_stop(TIMER0);

	portG_conf(1, EINT);
	portG_conf_pup(1, ENABLE);
	portG_eint_trig(1, FALLING);

	pISR_TIMER0   = (unsigned) timer0_ISR;
	pISR_EINT1    = (unsigned) keyboard_ISR;

	ic_init();
	ic_conf_irq(ENABLE, VEC);
	ic_conf_fiq(DISABLE);
	ic_conf_line(INT_TIMER0, IRQ);
	ic_conf_line(INT_EINT1, IRQ);
	ic_enable(INT_TIMER0);
	ic_enable(INT_EINT1);

	Delay(0);

	gstate = INIT;
	D8Led_digit(0xC);

	return 0;
}


int loop(void)
{
	int count;
	int error;

	switch (gstate)
	{
		case INIT:
			do {
				D8Led_digit(0xC);
				count = read_kbd(passwd);
				if(count < N)
				{
					D8Led_digit(0xE);
					Delay(10000);
				}
			} while (count < N);

			gstate = SPWD;
			break;
		case SPWD:
			printD8Led(passwd, N);
			Delay(10000);
			gstate = DOGUESS;
			break;
		case DOGUESS:
			Delay(10000);
			do {
				D8Led_digit(0xF);
				count = read_kbd(guess);
				if(count < N)
				{
					D8Led_digit(0xE);
					Delay(1000);
				}
			} while (count < N);

            gstate = SGUESS;
			break;
		case SGUESS:
			printD8Led(guess, N);
			Delay(10000);
            gstate = GOVER;            
			break;
		case GOVER:
			error = show_result();
			Delay(10000);            
			if(error)
			{
				gstate = DOGUESS;
			}
			else
			{
				gstate = INIT;
			}
			break;
	}
	
	return 0;
}

int main(void)
{
	setup();

	while (1)
	{
		loop();
	}
}
