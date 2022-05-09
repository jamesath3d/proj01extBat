
#include "main.h"

//        _Y1( LED_on,    led11 );
//        _Y1( LED_off,   led11 );

void led_1234_init_test_by_byte(uint8_t ___byte){
#ifndef led_1234_init_test_by_byte_ALL
#error "You must define led_1234_init_test_by_byte_ALL and run again"
#endif
    if ( ___byte & 0x01 ) { _Y1( LED_on,    led10 ); ; } else { _Y1( LED_off,   led10 ); }
    if ( ___byte & 0x02 ) { _Y1( LED_on,    led11 ); ; } else { _Y1( LED_off,   led11 ); }
    if ( ___byte & 0x04 ) { _Y1( LED_on,    led12 ); ; } else { _Y1( LED_off,   led12 ); }
    if ( ___byte & 0x08 ) { _Y1( LED_on,    led13 ); ; } else { _Y1( LED_off,   led13 ); }
    if ( ___byte & 0x10 ) { _Y1( LED_on,    led14 ); ; } else { _Y1( LED_off,   led14 ); }
}

void led_1234_init_test_loop(void){

    if ( 1 ) {
        led_1234_init_test_by_byte( led_1234_init_test_by_byte_ALL ) ;
        Delay_1ms();    // 0.001 second
        //while ( 1 ) {; }
    }

    while ( 0 ) {}

    while ( 0 ) { led_1234_init_test_by_byte( 0x00 ) ; }
    while ( 0 ) { led_1234_init_test_by_byte( 0x15 ) ; }
    while ( 0 ) { led_1234_init_test_by_byte( 0x0A ) ; }


    while ( 1 ) {
        led_1234_init_test_once();
    }
} // led_1234_init_test_loop

