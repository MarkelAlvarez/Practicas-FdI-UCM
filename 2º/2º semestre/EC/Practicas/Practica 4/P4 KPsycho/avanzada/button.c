/*-------------------------------------------------------------------
**
**  Fichero:
**    button.c  10/6/2014
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Automï¿½tica
**    Facultad de Informï¿½tica. Universidad Complutense de Madrid
**
**  Propï¿½sito:
**    Contiene las implementaciones de las funciones
**    para la gestiï¿½n de los pulsadores de la placa de prototipado
**
**  Notas de diseï¿½o:
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

	portG_read(6, &val);
	if(val == LOW) buttons |= BUT1;

	portG_read(7, &val);
	if (val == LOW) buttons |= BUT2;
	
	//COMPLETAR utilizando el interfaz del puerto G de gpio.h debemos leer los
	//pines 6 y 7 del puerto G (portG_read) debemos devolver un valor (buttons)
	//en el que el bit 0 (el menos significativo) representa el estado del botÃ³n
	//del pin 6 y el bit 1 representa el estado del botÃ³n del pin 7 (a 1 si
	//estÃ¡n pulsados a 0 si no lo estÃ¡n).
	
	return buttons;
}


