
#include "main.h"

static void led_1234_init_test_by_byte(uint8_t ___byte){
    if ( ___byte & 0x01 ) { led_10_on() ; } else { led_10_off(); }
    if ( ___byte & 0x02 ) { led_11_on() ; } else { led_11_off(); }
    if ( ___byte & 0x04 ) { led_12_on() ; } else { led_12_off(); }
    if ( ___byte & 0x08 ) { led_13_on() ; } else { led_13_off(); }
    if ( ___byte & 0x10 ) { led_14_on() ; } else { led_14_off(); }
}

void led_1234_init_test_loop(void){

    if ( 1 ) {
        led_1234_init_test_by_byte( 0x1F ) ;
        Delay_1ms();    // 0.001 second
        //while ( 1 ) {; }
    }

    while ( 0 ) {}

    while ( 0 ) { led_1234_init_test_by_byte( 0x00 ) ; }
    while ( 1 ) { led_1234_init_test_by_byte( 0x15 ) ; }
    while ( 1 ) { led_1234_init_test_by_byte( 0x0A ) ; }


    while ( 1 ) {
        led_1234_init_test_once();
    }
} // led_1234_init_test_loop

