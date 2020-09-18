#ifndef D8LED_H_
#define D8LED_H_

void D8Led_init(void);
void D8Led_segment(int value); 
void D8Led_digit(int value); 
void D8Led_2segments(int value0, int value1);

#endif