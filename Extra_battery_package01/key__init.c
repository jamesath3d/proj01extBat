
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

static uint8_t _key_1_toggle_step = 0 ;
static uint8_t _key_1_toggle_cnt = 0 ;
static uint8_t _key_1_value_t1 = 0 ;
#define _KEY_delay_cycle1    2
#define _KEY_delay_cycle2    1
void key_1_once_toggle_value_t1(void){

    switch ( _key_1_toggle_step ) {
        case 0 :  // waiting for key being pressed ( read 0 )
            if ( ! key_1_read() ) { // 0 --> key being pressed
                if ( _key_1_toggle_cnt >= _KEY_delay_cycle1 ) {
                    _key_1_toggle_cnt = 0 ;
                    _key_1_toggle_step ++ ; // go to next step
                } else {
                    _key_1_toggle_cnt ++ ; // waite until 16ms * 8 == 128 ms == 0.128 s
                }
            } else { // 1 --> key being released
                _key_1_toggle_cnt = 0 ; // not enoght timegap( 0.128 s)
            }
            break ;
        case 1 :  // waiting for key being release ( read 1 )
            if ( key_1_read() ) { // 1 --> key being released
                if ( _key_1_toggle_cnt >= _KEY_delay_cycle2 ) {
                    _key_1_toggle_cnt = 0 ;
                    _key_1_toggle_step ++ ; // go to next step
                } else {
                    _key_1_toggle_cnt ++ ; // waite until 16ms * 8 == 128 ms == 0.128 s
                }
            } else { // 0 --> key being pressed
                _key_1_toggle_cnt = 0 ; // not enoght timegap( 0.128 s)
            }
            break ;
        default :
            _key_1_toggle_step = 0 ; 
            _key_1_toggle_cnt = 0  ; 

            _key_1_value_t1 = ( ! _key_1_value_t1 ) ;
            break ;
    }

} // key_1_once_toggle_value_t1

void led34_follow_key1_onceX(void){

    if ( _key_1_value_t1 ) {
        led_14_TO_0();
    } else {
        led_14_TO_1();
    }

} // led34_follow_key1_onceX

static uint8_t led34_follow_key1_once_idx = 0 ;
void led34_follow_key1_once(void){

    led34_follow_key1_once_idx ++;
    if ( led34_follow_key1_once_idx >= 16 ) {
        led34_follow_key1_once_idx = 0;

        if ( _key_1_value_t1 ) {
            led_13_on();
        } else {
            led_14_on();
        }
        __delay_cycles(1); //__delay_cycles(1000);
        led_13_off();
        led_14_off();
    }

} // led34_follow_key1_once

