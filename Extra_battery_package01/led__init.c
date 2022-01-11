
#include "main.h"

static uint8_t _led_idx = 0 ;
void led_1234_init_test_loop(void){

    if ( 1 ) {
        led_11_on();
        led_12_on();
        led_13_on();
        led_14_on();
        //__delay_cycles(100000);    // 0.1 second
        __delay_cycles(1000);    // 0.001 second
        //while ( 1 ) {; }
    }

    while ( 1 ) {
        switch ( _led_idx & 0x3 ) {
            case 1  : led_11_on(); break ;
            case 2  : led_12_on(); break ;
            case 3  : led_13_on(); break ;
            default : led_14_on(); break ;
        }

          __delay_cycles(32);    // 0.001 second
        //__delay_cycles(1000);    // 0.001 second
        //__delay_cycles(10000);   // 0.01 second
        //__delay_cycles(100000);  // 0.1 second
        //__delay_cycles(1000000); // 1   second
        led_11_off()            ;
        led_12_off()            ;
        led_13_off()            ;
        led_14_off()            ;

        __delay_cycles(32768);  // 0.1 second
        //__delay_cycles(100000);  // 0.1 second
        //__delay_cycles(1000000); // 1   second
        //__delay_cycles(7000000); // 7   second
        //__delay_cycles(8000000); // 8   second
        //led_14_on()             ;
        //led_13_on()             ;
        _led_idx ++ ;
    }
}

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
