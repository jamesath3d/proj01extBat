
#ifndef __INTERUPT_TIMER_H__
#define __INTERUPT_TIMER_H__


#include "main.h"

// led11   
#define LedBr0   0b00000000
#define LedBr1   0b00000001
#define LedBr2   0b00000011
#define LedBr3   0b00000111
#define LedBr4   0b00001111
#define LedBr5   0b10001111
#define LedBrX   0b10000110

void interupt_init_ccr1_for_led_brightness(void) ;
extern volatile uint8_t ledB ;
extern const uint8_t ledBarr[] ;

#endif
