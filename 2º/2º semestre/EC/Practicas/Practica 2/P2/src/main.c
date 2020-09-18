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
	D8Led_segment(RL.position);
	
	portG_conf(6, INPUT);
	portG_conf(7, INPUT);
	portG_conf_pup(6, ENABLE);
	portG_conf_pup(7, ENABLE);

	Delay(0);

	return 0;
}

int loop(void)
{
	unsigned int buttons = read_button();

	if (buttons & BUT1)
	{
		led1_off();
		led2_off();

		RL.direction ^= 1;
	}
	if (buttons & BUT2)
	{
		contBUT2++;

		if(contBUT2 % 2 == 0)
		{
			led1_switch();
		}
		else
		{
			led2_switch();
		}

		RL.moving ^= 1;
	}
	if (!RL.moving)
	{
		RL.iter--;

		if (RL.iter <= 0)
		{
			if (RL.direction == 1)
			{
				RL.position++;
				RL.position %= 6;
			}
			else
			{
				RL.position -= 1;
				if (RL.position < 0)
				{
					RL.position = 5;
				}
				
			}

			D8Led_segment(RL.position);
			RL.iter = RL.speed;
		}
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