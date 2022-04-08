
#include "main.h"

static uint8_t _led_1234_idx = 0 ;
void led_1234_init_test_once(void){

    if ( 0 == _led_1234_idx ) {
        _led_1234_idx = led_1234_init_test_by_byte_MSB ;
    }
    led_1234_init_test_by_byte( _led_1234_idx );
    _led_1234_idx >>= 1 ;

    //Delay_1000ms();    // 1 second
    __delay_cycles(1000000)  ;

} // led_1234_init_test_once

