
#include "main.h"


static uint8_t _key_1_idx = 0 ;
void key_1_blink_once(void){

    _key_1_idx ++;
    if ( _key_1_idx >= 64 ) {
        _key_1_idx = 0;

        led_13_on();
        __delay_cycles(1); //__delay_cycles(1000);
        led_13_off();
    }
} // led_2_blink_once

