
#include "main.h"


static uint8_t key_1_blink_once_on_led3_idx = 0 ;
void key_1_blink_once_on_led3(void){

    key_1_blink_once_on_led3_idx ++;
    if ( key_1_blink_once_on_led3_idx >= 8 ) {
        key_1_blink_once_on_led3_idx = 0;

        if ( key_1_read() ) {
            led_13_off();
        } else {
            led_13_on();
        }
    }
} // key_1_blink_once_on_led3

