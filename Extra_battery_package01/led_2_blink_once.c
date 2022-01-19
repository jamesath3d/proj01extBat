
#include "main.h"

static uint8_t led_2_blink_once_idx = 0 ;
void led_2_blink_once(void){

    led_2_blink_once_idx ++;
    if ( led_2_blink_once_idx >= 32 ) {
        led_2_blink_once_idx = 0;

        led_12_on();
        __delay_cycles(1); //__delay_cycles(1000);
        led_12_off();
    }
} // led_2_blink_once

