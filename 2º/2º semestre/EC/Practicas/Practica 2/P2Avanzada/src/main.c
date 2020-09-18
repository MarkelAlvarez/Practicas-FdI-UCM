#include <stdio.h>
#include "44b.h"
#include "button.h"
#include "leds.h"
#include "utils.h"
#include "D8Led.h"
#include "gpio.h"

struct RLstat {
	int moving;
	int speed;
	int iter;
	int direction;
	int position;
};

static struct RLstat RL = {
	.moving = 0,
	.speed = 5,
	.iter = 0,
	.direction = 0,
	.position = 0,
};

static int contBUT2 = 0;

int setup(void)
{
	leds_init();
	D8Led_init();
	//D8Led_digit(14);
	//D8Led_segment(RL.position);
	
	portG_conf(6, INPUT);
	portG_conf(7, INPUT);
	portG_conf_pup(6, ENABLE);
	portG_conf_pup(7, ENABLE);

	Delay(0);

	return 0;
}

int loop(void)
{
	static int veces = 0;
	unsigned int buttons = read_button();

	if (buttons & BUT1)
	{
		veces++;
	}
	if (veces == 4)
	{
		D8Led_digit(14);

		Delay(3000);

		D8Led_digit(12);

		veces = 0;
	}

	Delay(2000);

	return 0;
}


int main(void)
{
	setup();

	while (1)
	{
		loop();
	}
}
