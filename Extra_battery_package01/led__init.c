
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
    led_11_init();
    led_12_init();
    led_13_init();
    led_14_init();

    led_11_off();
    led_12_off();
    led_13_off();
    led_14_off();
}

static uint8_t led_1_blink_once_idx = 0 ;
void led_1_blink_once(void){

    led_1_blink_once_idx ++;
    if ( led_1_blink_once_idx >= 16 ) {
        led_1_blink_once_idx = 0;

        led_11_on();
        __delay_cycles(1); //__delay_cycles(1000);
        led_11_off();
    }
} // led_1_blink_once

static uint8_t led_2_blink_once_idx = 0 ;
void led_2_blink_once(void){

    led_2_blink_once_idx ++;
    if ( led_2_blink_once_idx >= 32 ) {
        led_2_blink_once_idx = 0;

        led_12_on();
        __delay_cycles(1); //__delay_cycles(1000);
        led_12_off();
    }
} // led_2_blink_once

