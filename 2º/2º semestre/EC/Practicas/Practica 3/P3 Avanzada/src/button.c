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
	if(val == LOW)
	{
		buttons |= BUT1;
	}

	portG_read(7, &val);
	if (val == LOW)
	{
		buttons |= BUT2;
	}

	return buttons;
}


