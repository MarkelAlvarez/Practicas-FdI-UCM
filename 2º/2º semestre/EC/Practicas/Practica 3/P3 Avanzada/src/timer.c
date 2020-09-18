#include "44b.h"
#include "timer.h"

int tmr_set_mode(enum tmr_timer t, enum tmr_mode mode)
{
	int err = 0, pos = t*4;
	
	if (t > 0)
	{
		pos += 4;
	}
	if (t < 0 || t > 5)
	{
		return -1;
	}

	if (mode == ONE_SHOT)
	{
		rTCON = rTCON & ~(0x8 << pos);
	}
	else if (mode == RELOAD)
	{
		rTCON = rTCON | (0x8 << pos);
	}
	else
	{
		err = -1;
	}

	return err;
}

int tmr_update(enum tmr_timer t)
{
	int pos = t*4;

	if (t > 0)
	{
		pos += 4;
	}

	if (t < 0 || t > 5)
	{
		return -1;
	}

	rTCON = rTCON | (0x2 << pos);
	rTCON = rTCON & ~(0x2 << pos);

	return 0;
}

int tmr_start(enum tmr_timer t)
{
	int pos = t*4;

	if (t > 0)
	{
		pos += 4;
	}
	if (t < 0 || t > 5)
	{
		return -1;
	}

	rTCON = rTCON | (0x1 << pos);

	return 0;
}

int tmr_stop(enum tmr_timer t)
{
	int pos = t*4;

	if (t > 0)
	{
		pos += 4;
	}
	if (t < 0 || t > 5)
	{
		return -1;
	}

	rTCON = rTCON & ~(0x1 << pos);

	return 0;
}

int tmr_set_prescaler(int p, int  value)
{
	int offset = p*8;

	value &= 0xFF;

	if (p < 0 || p > 3)
	{
		return -1;
	}

	rTCFG0 = rTCFG0 & ~(0xFF << offset);
	rTCFG0 = rTCFG0  | (value << offset);

	return 0;
}

int tmr_set_divider(int d, enum tmr_div div)
{
	int ret = 0, pos = d*4;

	if ((d < 0 || d > 5) ||	(div == D1_32 && d > 3) || (div == EXTCLK && d != 5) ||	(div == TCLK && d != 4))
	{
		return -1;
	}

	if (div == EXTCLK || div == TCLK)
	{
		div = 4;
	}

	rTCFG1 = rTCFG1 & ~(0x7 << pos);
	rTCFG1 = rTCFG1 | (div << pos);

	return 0;
}

int tmr_set_count(enum tmr_timer t, int count, int cmp)
{
	int err = 0;

	switch (t)
	{
		case TIMER0:
			rTCNTB0 = count;
			rTCMPB0 = cmp;
			break;
		case TIMER1:
			rTCNTB1 = count;
			rTCMPB1 = cmp;
			break;
		case TIMER2:
			rTCNTB2 = count;
			rTCMPB2 = cmp;
			break;
		case TIMER3:
			rTCNTB3 = count;
			rTCMPB3 = cmp;
			break;
		case TIMER4:
			rTCNTB4 = count;
			rTCMPB4 = cmp;
			break;
		case TIMER5:
			rTCNTB5 = count;
			break;
		default:
			err = -1;
	}

	return err;
}

int tmr_isrunning(enum tmr_timer t)
{
	int ret = 0, pos = t*4;

	if (t > 0)
	{
		pos += 4;
	}

	if ((t >= 0) && (t <= 5) && (rTCON & (0x1 << pos)))
	{
		ret = 1;
	}

	return ret;
}
