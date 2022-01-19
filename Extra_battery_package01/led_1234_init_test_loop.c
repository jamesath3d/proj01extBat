
#include "main.h"


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

