
#include "main.h"

void led_1234_init_test_once_only(void){
    static uint8_t __led_1234_idx = 0 ;

    if ( 0 == __led_1234_idx ) {
        __led_1234_idx = led_1234_init_test_by_byte_MSB ;
    }
    led_1234_init_test_by_byte( __led_1234_idx );
    __led_1234_idx >>= 1 ;

} // led_1234_init_test_once_only

void led_1234_init_test_once_all_by_lpm(void){
    static uint8_t __led_1234_id2 = 0 ;

    __led_1234_id2 = led_1234_init_test_by_byte_MSB ;
    while ( __led_1234_id2 ) {
        for ( uint8_t ii = 8; ii > 0 ; ii -- ) {
            _WDT_wait_interrupt_LPM3;
        }
        led_1234_init_test_by_byte( __led_1234_id2 );
        __led_1234_id2 >>= 1 ;
    }

} // led_1234_init_test_once_all_by_lpm

void led_1234_init_test_once(void){

    led_1234_init_test_once_only();

    Delay_1000ms();    // 1 second
    //__delay_cycles(1000000)  ;

} // led_1234_init_test_once

