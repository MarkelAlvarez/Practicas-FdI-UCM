#include "44b.h"
#include "intcontroller.h"

void ic_init(void)
{
	/* Configuración por defector del controlador de interrupciones:
	 *    Lineas IRQ y FIQ no habilitadas
	 *    Linea IRQ en modo no vectorizado
	 *    Todo por la línea IRQ
	 *    Todas las interrupciones enmascaradas
	 **/
	rINTMOD = 0x0; // Configura las linas como de tipo IRQ
	rINTCON = 0x7; // IRQ y FIQ enmascaradas, IRQ en modo no vectorizado
	rINTMSK = ~(0x0); // Enmascara todas las lineas
}

int ic_conf_irq(enum enable st, enum int_vec vec)
{
	int conf = rINTCON;

	if (st != ENABLE && st != DISABLE)
		return -1;

	if (vec == VEC)
	{
		conf = conf & ~(0x1 << 2);
	}
	else
	{
		conf = conf & ~(0x1 << 1);
		conf = conf | (0x1 << 2);
	}
	if (st == ENABLE)
	{
		conf = conf & ~(0x1 << 1);
	}
	else
	{
		conf = conf | (0x1 << 1);
	}

	rINTCON = conf;
	return 0;
}

int ic_conf_fiq(enum enable st)
{
	int ret = 0;

	if (st == ENABLE)
	{
		rINTCON = rINTCON & ~(0x1 << 0);
	}
	else if (st == DISABLE)
	{
		rINTCON = rINTCON | (0x1 << 0);
	}
	else
	{
		ret = -1;
	}

	return ret;
}

int ic_conf_line(enum int_line line, enum int_mode mode)
{
	unsigned int bit = INT_BIT(line);

	if (line < 0 || line > 26)
	{
		return -1;
	}

	if (mode != IRQ && mode != FIQ)
	{
		return -1;
	}

	if (mode == IRQ)
	{
		rINTMOD = rINTMOD & ~(0x1 << line);
	}
	else
	{
		rINTMOD = rINTMOD | (0x1 << line);
	}

	return 0;
}

int ic_enable(enum int_line line)
{
	if (line < 0 || line > 26)
	{
		return -1;
	}

	rINTMSK = rINTMSK & ~(0x1 << line);
	rINTMSK = rINTMSK & ~(0x1 << 26);

	return 0;
}

int ic_disable(enum int_line line)
{
	if (line < 0 || line > 26)
	{
		return -1;
	}

	rINTMSK = rINTMSK | (0x1 << line);
	
	return 0;
}

int ic_cleanflag(enum int_line line)
{
	int bit;

	if (line < 0 || line > 26)
	{
		return -1;
	}

	bit = INT_BIT(line);

	if (rINTMOD & bit)
	{
		rF_ISPC = bit;
	}
	else
	{
		rI_ISPC = bit;
	}

	return 0;
}