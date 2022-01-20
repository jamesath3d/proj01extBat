
#include "main.h"

extern uint8_t _key_1_value_t1 ;

void led_34_follow_key1_onceX(void){

    if ( _key_1_value_t1 ) {
        led_14_TO_0();
    } else {
        led_14_TO_1();
    }

} // led_34_follow_key1_onceX

static uint8_t led34_follow_key1_once_idx = 0 ;
void led_34_follow_key1_t1_once(void){

    led34_follow_key1_once_idx ++;
    //if ( led34_follow_key1_once_idx >= 16 ) {
    //    led34_follow_key1_once_idx = 0;
    //if ( 1 == (led34_follow_key1_once_idx & 0x3 ) ) {
    if ( 1 == 1 ) {

        if ( _key_1_value_t1 ) {
            led_14_on();
        } else {
            led_13_on();
        }
        //__delay_cycles(1); //__delay_cycles(1000);
        led_13_off();
        led_14_off();
    }

} // led_34_follow_key1_t1_once

