/*******************************************************************************************
* File:		keyboard.c
* Author:	
* Desc:		Funciones de teclado
* History:	
*********************************************************************************************/

/*--- Ficheros de cabecera ---*/
#include "44b.h"
#include "keyboard.h"

/*--- Definición de macros ---*/
#define KEY_VALUE_MASK	0x0f

/*--- Variables globales ---*/
volatile static unsigned char *keyboard_base = (unsigned char *)0x06000000;


int kb_scan(void)
{
	int value = -1;
	int i;
	char temp;
	int lines[4]  = {0xfd, 0xfb, 0xf7, 0xef};
	int map[4][4] = {{0, 1, 2, 3},
					{4, 5, 6, 7},
					{8, 9, 0xA, 0xB},
					{0xC, 0xD, 0xE, 0xF}};

	for (i = 0; (i < 4) && (value == -1); i++) {
		temp = *(keyboard_base+lines[i]);

		if(( temp & KEY_VALUE_MASK) != KEY_VALUE_MASK) {
			//COMPLETAR: 
			//      si está el bit 1 a 0 la tecla es la map[i][3]
			//      si está el bit 2 a 0 la tecla es la map[i][2]
			//      si está el bit 3 a 0 la tecla es la map[i][1]
			//      si está el bit 4 a 0 la tecla es la map[i][0]
		}
	}

	return value;
}
