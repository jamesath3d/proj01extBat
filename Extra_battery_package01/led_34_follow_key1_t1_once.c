
#include "main.h"

extern uint8_t _key_1_value_t1 ;

//        _Y1( LED_on,    led11 );
//        _Y1( LED_off,   led11 );
void led_34_follow_key1_onceX(void){

    if ( _key_1_value_t1 ) {
        _Y1( LED_off,   led14 );
    } else {
        _Y1( LED_on,   led14 );
    }

} // led_34_follow_key1_onceX

static uint8_t led34_follow_key1_once_idx = 0 ;
void led_34_follow_key1_t1_once(void){

    led34_follow_key1_once_idx ++;
    //if ( led34_follow_key1_once_idx >= 16 ) {
    if ( 0 == (led34_follow_key1_once_idx & 0xF ) ) {
    //if ( 0 == (led34_follow_key1_once_idx & 0x7 ) ) {
    //if ( 0 == (led34_follow_key1_once_idx & 0x3 ) ) {
    //if ( 1 == 1 ) {

        if ( _key_1_value_t1 ) {
            _Y1( LED_on,    led14 );
            __delay_cycles(200); // 10us @ mclk 1Mhz
            _Y1( LED_off,   led14 );
        } else {
            _Y1( LED_on,    led13 );
            __delay_cycles(200); // 10us @ mclk 1Mhz
            _Y1( LED_off,   led13 );
        }
    }

} // led_34_follow_key1_t1_once

