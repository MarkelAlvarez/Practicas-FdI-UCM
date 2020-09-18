/*-------------------------------------------------------------------
**
**  Fichero:
**    button.c  10/6/2014
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Autom�tica
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las implementaciones de las funciones
**    para la gesti�n de los pulsadores de la placa de prototipado
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#include "44b.h"
#include "utils.h"
#include "button.h"
#include "leds.h"
#include "gpio.h"

unsigned int read_button(void)
{
	unsigned int buttons = 0;
	enum digital val;

	//COMPLETAR utilizando el interfaz del puerto G de gpio.h debemos leer los
	//pines 6 y 7 del puerto G (portG_read) debemos devolver un valor (buttons)
	//en el que el bit 0 (el menos significativo) representa el estado del botón
	//del pin 6 y el bit 1 representa el estado del botón del pin 7 (a 1 si
	//están pulsados a 0 si no lo están).
	

	return buttons;
}


