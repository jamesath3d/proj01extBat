
#include "main.h"

static uint8_t led_1_blink_once_idx = 0 ;
void led_1_blink_once(void){

    led_1_blink_once_idx ++;
    if ( led_1_blink_once_idx >= 16 ) {
        led_1_blink_once_idx = 0;

        led_11_on();
        __delay_cycles(1); //__delay_cycles(1000);
        led_11_off();
    }
} // led_1_blink_once

