#include <stdio.h>
#include "44b.h"
#include "button.h"
#include "leds.h"
#include "utils.h"
#include "D8Led.h"
#include "intcontroller.h"
#include "timer.h"
#include "gpio.h"
#include "keyboard.h"

struct RLstat {
	int moving;
	int speed;
	int direction;
	int position;
};

static struct RLstat RL = {
	.moving = 1,
	.speed = 5,
	.direction = 0,
	.position = 0,
};

void timer_ISR(void) __attribute__ ((interrupt ("IRQ")));
void button_ISR(void) __attribute__ ((interrupt ("IRQ")));
void keyboard_ISR(void) __attribute__ ((interrupt ("IRQ")));

void timer_ISR(void)
{
	if(RL.direction == 1)
	{
		if(RL.position < 5)
		{
			RL.position++;
		}
		else
		{
			RL.position = 0;
		}
	}
	else if(RL.direction == 0)
	{
		if(RL.position > 0)
		{
			RL.position--;
		}
		else
		{
			RL.position = 5;
		}
	}

	D8Led_segment(RL.position);
	ic_cleanflag(INT_TIMER0);
}

void button_ISR(void)
{
	unsigned int whicheint = rEXTINTPND;
	unsigned int buttons = (whicheint >> 2) & 0x3;

	if (buttons == BUT1)
	{
		led1_switch();
		RL.direction ^= 1;
	}
	if (buttons == BUT2)
	{
		led2_switch();
		if(RL.moving == 0)
		{
			RL.moving = 1;
			tmr_update(TIMER0);
			tmr_start(TIMER0);
		}
		else
		{
			RL.moving = 0;
			tmr_stop(TIMER0);
		}
	}

	Delay(2000);

	if (rEXTINTPND & 0x4)
	{
		rEXTINTPND |= (0x1 << 2);
	}
	else if(rEXTINTPND & 0x8)
	{
		rEXTINTPND |= (0x1 << 3);
	}

	ic_cleanflag(INT_EINT4567);
}

void keyboard_ISR(void)
{
	int key;

	Delay(200);
	
	key = kb_scan();

	if (key != -1)
	{
		D8Led_digit(key);

		switch (key)
		{
			case 0:
				tmr_set_divider(TIMER0, D1_8);
				tmr_set_count(TIMER0, 62500, 62000);
				tmr_update(TIMER0);
				break;
			case 1:
				tmr_set_divider(TIMER0, D1_8);
				tmr_set_count(TIMER0, 31250, 31000);
				tmr_update(TIMER0);
				break;
			case 2:
				tmr_set_divider(TIMER0, D1_8);
				tmr_set_count(TIMER0, 15625, 15500);
				tmr_update(TIMER0);
				break;
			case 3:
				tmr_set_divider(TIMER0, D1_4);
				tmr_set_count(TIMER0, 15625, 15500);
				tmr_update(TIMER0);
				break;
			default:
				break;
		}
		
		if (rPDATG & 0x2){};
	}

    Delay(200);

    ic_cleanflag(INT_EINT1);
}

int setup(void)
{
	leds_init();
	D8Led_init();
	D8Led_segment(RL.position);

	portG_conf(1, EINT);
	portG_conf(6, EINT);
	portG_conf(7, EINT);

	portG_eint_trig(1, FALLING);
	portG_eint_trig(6, FALLING);
	portG_eint_trig(7, FALLING);

	portG_conf_pup(1, ENABLE);
	portG_conf_pup(6, ENABLE);
	portG_conf_pup(7, ENABLE);

	tmr_set_prescaler(0, 255);
	tmr_set_divider(0, D1_8);
	tmr_set_count(TIMER0, 62500, 31250);
	tmr_update(TIMER0);
	tmr_set_mode(TIMER0, RELOAD);
	tmr_stop(TIMER0);

	if(RL.moving)
	{
		tmr_start(TIMER0);
	}

	pISR_TIMER0   = (unsigned) timer_ISR;
	pISR_EINT4567 = (unsigned) button_ISR;
	pISR_EINT1    = (unsigned) keyboard_ISR;

	ic_init();
	ic_conf_irq(ENABLE, VEC);
	ic_conf_fiq(DISABLE);
	ic_conf_line(INT_TIMER0, IRQ);
	ic_conf_line(INT_EINT4567, IRQ);
	ic_conf_line(INT_EINT1, IRQ);
	ic_enable(INT_TIMER0);
	ic_enable(INT_EINT4567);
	ic_enable(INT_EINT1);

	Delay(0);
	return 0;
}

int loop(void)
{
	return 0;
}

int main(void)
{
	setup();

	while (1)
	{
		//loop();
	}

	return 0;
}
