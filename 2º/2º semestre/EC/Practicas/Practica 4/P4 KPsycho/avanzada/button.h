/*-----------------------------------------------------------------
**
**  Fichero:
**    button.c  10/6/2014
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Autom�tica
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para la gesti�n de los pulsadores de la placa de prototipado
**
**  Notas de dise�o:
**
**---------------------------------------------------------------*/

#ifndef BUTTON_H_
#define BUTTON_H_

#define BUT1 0x1 // a 1 si se pulsa el boton
#define BUT2 0x2 // " " " " " 
				 // Mascara con and 000000000 para detectar la pulsacion del boton

unsigned int read_button(void);

#endif /* BUTTON_H_ */
