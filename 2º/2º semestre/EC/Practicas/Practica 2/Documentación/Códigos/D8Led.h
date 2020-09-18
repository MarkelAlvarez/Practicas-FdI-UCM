/*-------------------------------------------------------------------
**
**  Fichero:
**    D8Led.h  10/6/2014
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Contiene las declaraciones de los prototipos de funciones
**    para el acceso al display 8-segmentos de la placa de prototipado
**
**  Notas de diseño:
**    Equivale al fichero homónimo usado en Fundamentos de Computadores 
**
**-----------------------------------------------------------------*/

#ifndef D8LED_H_
#define D8LED_H_

void D8Led_init(void);
void D8Led_segment(int value); 
void D8Led_digit(int value); 

#endif

