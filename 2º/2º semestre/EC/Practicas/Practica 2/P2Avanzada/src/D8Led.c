#include "44b.h"
#include "D8Led.h"

#define SEGMENT_A		0x80		
#define SEGMENT_B		0x40
#define SEGMENT_C		0x20
#define SEGMENT_D		0x08
#define SEGMENT_E		0x04
#define SEGMENT_F		0x02
#define SEGMENT_G		0x01
#define SEGMENT_P		0x10

#define DIGIT_0  ( SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_G )
#define DIGIT_1  ( SEGMENT_B | SEGMENT_C )
#define DIGIT_2  ( SEGMENT_A | SEGMENT_B | SEGMENT_F | SEGMENT_E | SEGMENT_D )
#define DIGIT_3  ( SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F )
#define DIGIT_4  ( SEGMENT_F | SEGMENT_B | SEGMENT_C | SEGMENT_G )
#define DIGIT_5  ( SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_G | SEGMENT_F )
#define DIGIT_6  ( SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G )
#define DIGIT_7  ( SEGMENT_A | SEGMENT_B | SEGMENT_C )
#define DIGIT_8  ( SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G )
#define DIGIT_9  ( SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_F | SEGMENT_G )
#define DIGIT_A  ( SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_E | SEGMENT_F | SEGMENT_G )
#define DIGIT_B  ( SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G )
#define DIGIT_C  ( SEGMENT_D | SEGMENT_E | SEGMENT_F )
#define DIGIT_D  ( SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F )
#define DIGIT_E  ( SEGMENT_A | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G )
#define DIGIT_F  ( SEGMENT_A | SEGMENT_E | SEGMENT_F | SEGMENT_G )


/* Tablas para facilitar el uso del display */

static unsigned int Segments[] = { SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_D,
	                               SEGMENT_E, SEGMENT_G, SEGMENT_F, SEGMENT_P };

static unsigned int Digits[] = { DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, 
	 							 DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7, 
								 DIGIT_8, DIGIT_9, DIGIT_A, DIGIT_B,
								 DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F };
			  					  
void D8Led_init(void)
{
    LED8ADDR = ~0 ;
}

void D8Led_segment(int value)
{
	if( (value >= 0) && (value < 8) )
	{
		LED8ADDR = ~Segments[value];
	}
}

void D8Led_digit(int value)
{
	if( (value >= 0) && (value < 16) )
	{
		LED8ADDR = ~Digits[value];
	}
}
