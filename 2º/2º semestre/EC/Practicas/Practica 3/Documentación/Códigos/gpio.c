#include "44b.h"
#include "gpio.h"

/* Port B interface implementation */

int portB_conf(int pin, enum port_mode mode)
{
	int ret = 0;
	if (pin < 0 || pin > 10)
		return -1;

	if (mode == SIGOUT)
		// COMPLETAR si es necesario
	else if (mode == OUTPUT)
		// COMPLETAR: tomar la implementación prácticas anteriores
	else
		ret = -1;

	return ret;
}

int portB_write(int pin, enum digital val)
{
	if (pin < 0 || pin > 10)
		return -1;

	if (val < 0 || val > 1)
		return -1;

	if (val)
		// COMPLETAR: tomar la implementación prácticas anteriores
	else
		// COMPLETAR: tomar la implementación prácticas anteriores

	return 0;
}

/* Port G interface implementation */

int portG_conf(int pin, enum port_mode mode)
{
	int pos  = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	switch (mode) {
		case INPUT:
		// COMPLETAR: tomar la implementación prácticas anteriores
			break;
		case OUTPUT:
		// COMPLETAR: tomar la implementación prácticas anteriores
			break;
		case SIGOUT:
		// COMPLETAR: tomar la implementación prácticas anteriores
			break;
		case EINT:
		// COMPLETAR: tomar la implementación prácticas anteriores
			break;
		default:
			return -1;
	}

	return 0;
}

int portG_eint_trig(int pin, enum trigger trig)
{
	int pos = pin*4;

	if (pin < 0 || pin > 7)
		return -1;

switch (trig) {
		case LLOW:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 000, para configurar interrupciones externas por nivel bajo
			break;
		case LHIGH:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 001, para configurar interrupciones externas por nivel alto
			break;
		case FALLING:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 010, para configurar interrupciones externas por flanco de
			// bajada
			break;
		case RISING:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 100, para configurar interrupciones externas por flanco de
			// subida
			break;
		case EDGE:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 110, para configurar interrupciones externas por cualquier
			// flanco
			break;
		default:
			return -1;
	}
	return 0;
}

int portG_write(int pin, enum digital val)
{
	int pos = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	if (val < 0 || val > 1)
		return -1;

	if ((rPCONG & (0x3 << pos)) != (0x1 << pos))
		return -1;

	if (val)
		// COMPLETAR: tomar la implementación prácticas anteriores
	else
		// COMPLETAR: tomar la implementación prácticas anteriores

	return 0;
}

int portG_read(int pin, enum digital* val)
{
	int pos = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	if (rPCONG & (0x3 << pos))
		return -1;

	if (rPDATG & (0x1 << pin))
		// COMPLETAR: tomar la implementación prácticas anteriores
	else
		// COMPLETAR: tomar la implementación prácticas anteriores

	return 0;
}

int portG_conf_pup(int pin, enum enable st)
{
	if (pin < 0 || pin > 7)
		return -1;

	if (st != ENABLE && st != DISABLE)
		return -1;

	if (st == ENABLE)
		// COMPLETAR: tomar la implementación prácticas anteriores
	else
		// COMPLETAR: tomar la implementación prácticas anteriores

	return 0;
}

