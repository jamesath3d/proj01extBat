
#include "main.h"

static uint8_t _led_idx = 0 ;
void led_1234_init_test_once(void){

    switch ( _led_idx & 0x3 ) {
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

    _led_idx ++ ;
} // led_1234_init_test_once

void led_1234_init_test_loop(void){

    if ( 1 ) {
        led_11_on();
        led_12_on();
        led_13_on();
        led_14_on();
        Delay_1ms();    // 0.001 second
        //while ( 1 ) {; }
    }

    while ( 1 ) {
        led_1234_init_test_once();
    }
} // led_1234_init_test_loop

void led_1234_init(void){
    led_11_set_out();
    led_12_set_out();
    led_13_set_out();
    led_14_set_out();

    led_11_off();
    led_12_off();
    led_13_off();
    led_14_off();
}
