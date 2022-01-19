
#include "main.h"

uint8_t _key_1_value_t1 = 0 ;

static uint8_t _key_1_toggle_step = 0 ;
static uint8_t _key_1_toggle_cnt = 0 ;
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

