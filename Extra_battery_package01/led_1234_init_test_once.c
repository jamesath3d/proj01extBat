
#include "main.h"

static uint8_t _led_1234_idx = 0 ;
void led_1234_init_test_once(void){

    switch ( _led_1234_idx & 0x3 ) {
        case 1  : led_11_on(); break ;
        case 2  : led_12_on(); break ;
        case 3  : led_13_on(); break ;
        default : led_14_on(); break ;
    }

    Delay_1ms();       // 0.001 second
    led_11_off()            ;
    led_12_off()            ;
    led_13_off()            ;
    led_14_off()            ;
    Delay_1000ms();    // 1 second

    _led_1234_idx ++ ;
} // led_1234_init_test_once

