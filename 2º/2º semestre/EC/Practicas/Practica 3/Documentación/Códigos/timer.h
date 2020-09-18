/*-------------------------------------------------------------------
**
**  Fichero:
**    tiemr.h  3/3/2016
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Contiene las definiciones de los prototipos de funciones
**    de gestión del timer
**
**-----------------------------------------------------------------*/

#ifndef TIMER_H_
#define TIMER_H_

enum tmr_timer {
	TIMER0 = 0,
	TIMER1 = 1,
	TIMER2 = 2,
	TIMER3 = 3,
	TIMER4 = 4,
	TIMER5 = 5
};

enum tmr_div {
	D1_2 = 0,
	D1_4 = 1,
	D1_8 = 2,
	D1_16 = 3,
	D1_32 = 4,
	EXTCLK = 5,
	TCLK = 6
};

enum tmr_mode {
	ONE_SHOT = 0,
	RELOAD = 1
};

int tmr_set_prescaler(int p, int  value);

int tmr_set_divider(int d, enum tmr_div div);

int tmr_set_count(enum tmr_timer t, int count, int cmp);

int tmr_set_mode(enum tmr_timer t, enum tmr_mode mode);

int tmr_update(enum tmr_timer t);

int tmr_start(enum tmr_timer t);

int tmr_stop(enum tmr_timer t);

int tmr_isrunning(enum tmr_timer t);

#endif
