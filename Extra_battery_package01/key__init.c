
#include "main.h"


static uint8_t _key_1_idx = 0 ;
void key_1_blink_once(void){

    _key_1_idx ++;
    if ( _key_1_idx >= 8 ) {
        _key_1_idx = 0;

        if ( key_1_read() ) {
            led_13_off();
        } else {
            led_13_on();
        }
    }
} // key_1_blink_once

static uint8_t _key_1_toggle_cnt = 0 ;
void key_1_toggle_once(void){

    _key_1_toggle_cnt ++;
    if ( _key_1_toggle_cnt >= 16 ) {
        _key_1_toggle_cnt = 0;

        if ( key_1_read() ) {
            led_14_off();
        } else {
            led_14_on();
        }
    }
} // key_1_toggle_once

