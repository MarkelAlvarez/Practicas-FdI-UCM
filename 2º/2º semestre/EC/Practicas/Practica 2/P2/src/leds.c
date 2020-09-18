#include "44b.h"
#include "leds.h"
#include "gpio.h"

// Mascaras de bits
#define LED1 0x01
#define LED2 0x02
#define BIT_LED1 9
#define BIT_LED2 10

// status representa el estado de los leds
// s�lo tienen sentido los dos bites menos
// significativos, cada uno para un led
// 1 encendido y 0 apagado
static unsigned int status = 0;

void leds_init( void )
{
	portB_conf(BIT_LED1, OUTPUT);
	portB_conf(BIT_LED2, OUTPUT);

	leds_display( status );
}

void led1_on( void )
{
	status |=  LED1;
	leds_display( status );
}

void led1_off( void )
{
	status &=  ~LED1;
	leds_display( status );
}

void led2_on( void )
{
	status |=  LED2;
	leds_display( status );
}

void led2_off( void )
{
	status &=  ~LED2;
	leds_display( status );
}

void led1_switch( void )
{
	status ^= LED1;
	leds_display( status );
}

void led2_switch( void )
{
	status ^= LED2;
	leds_display( status );
}

void leds_switch( void ){
	status ^= (LED1 | LED2);
	leds_display( status );
}

void leds_display( unsigned int leds_status )
{
	status = leds_status;
	
	// LED 1
	if( status & LED1 )
	{
		portB_write(BIT_LED1, LOW);
	}
	else
	{
		portB_write(BIT_LED1, HIGH);
	}
	// LED 2
	if( status & LED2 )
	{
		portB_write(BIT_LED2, LOW);
	}
	else
	{
		portB_write(BIT_LED2, HIGH);
	}
}