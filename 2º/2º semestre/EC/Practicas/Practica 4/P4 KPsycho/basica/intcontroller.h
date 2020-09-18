/*-------------------------------------------------------------------
**
**  Fichero:
**    intcontroller.h  3/3/2016
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Contiene las definiciones de los prototipos de funciones
**    de configuración general del controlador de interrupciones
**
**-----------------------------------------------------------------*/
#ifndef INTCONTROLLER_H
#define INTCONTROLLER_H
/*--- ficheros de cabecera ---*/
#include "44b.h"

#define INT_BIT(x) (0x1 << (x))

enum int_mode {
	IRQ = 0,
	FIQ = 1
};

enum int_vec {
	VEC = 0,
	NOVEC = 1
};

enum int_line {
	INT_ADC		 = 0,
	INT_RTC		 = 1,
	INT_UTXD1	 = 2,
	INT_UTXD0	 = 3,
	INT_SIO		 = 4,
	INT_IIC		 = 5,
	INT_URXD1	 = 6,
	INT_URXD0	 = 7,
	INT_TIMER5	 = 8,
	INT_TIMER4	 = 9,
	INT_TIMER3	 = 10,
	INT_TIMER2	 = 11,
	INT_TIMER1	 = 12,
	INT_TIMER0	 = 13,
	INT_UERR01	 = 14,
	INT_WDT		 = 15,
	INT_BDMA1	 = 16,
	INT_BDMA0	 = 17,
	INT_ZDMA1	 = 18,
	INT_ZDMA0	 = 19,
	INT_TICK	 = 20,
	INT_EINT4567 = 21,
	INT_EINT3	 = 22,
	INT_EINT2	 = 23,
	INT_EINT1	 = 24,
	INT_EINT0	 = 25,
	INT_GLOBAL	 = 26
};

void ic_init(void);

int ic_conf_irq(enum enable st, enum int_vec vec);

int ic_conf_fiq(enum enable st);

int ic_conf_line(enum int_line line, enum int_mode mode);

int ic_enable(enum int_line);

int ic_disable(enum int_line);

int ic_cleanflag(enum int_line line);

#endif

