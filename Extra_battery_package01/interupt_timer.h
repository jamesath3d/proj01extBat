
#ifndef __INTERUPT_TIMER_H__
#define __INTERUPT_TIMER_H__


#include "main.h"

// led11   

//#define LedBr0      0b10001111
//#define LedBr1      0b11110111
//#define LedBr2      0b11110011
//#define LedBr3      0b11110001
//#define LedBr4      0b11110000
//#define LedBr5      0b01110000
//#define LedBrX      0b11111001
//#define LedBrMask   LedBr0

#define LedBr0      0b00000000
#define LedBr1      0b00001000
#define LedBr2      0b00001100
#define LedBr3      0b00001110
#define LedBr4      0b00001111
#define LedBr5      0b10001111
#define LedBrX      0b10000110
#define LedBrY      0b10001001
#define LedBrMask   0b01110000

void interupt_init_ccr1_for_led_brightness(void) ;
void interupt_init_ccr1_for_led_off(void) ;
void interupt_init_ccr1_for_led_on(void) ;
extern volatile uint8_t ledB ;
extern const uint8_t ledBarr[] ;

#endif
