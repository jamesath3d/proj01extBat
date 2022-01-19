

#include "main.h"

static uint8_t _wdt_cnt01 = 0 ;
void wdt_test(void) {

    _WDT_init;

    //P1DIR    |= BIT6 ;
    led_1234_init_all_off() ;

    while( 1 ){

        _WDT_wait_interrupt ;

        _wdt_cnt01 ++;
        if ( _wdt_cnt01 >= 16 ) {
            _wdt_cnt01 = 0;

            //P1OUT &= ~BIT6 ; // on
            //__delay_cycles(1); //__delay_cycles(1000);
            //P1OUT |= BIT6 ; // off

            led_11_on();
            __delay_cycles(1); //__delay_cycles(1000);
            led_11_off();
        }


    }

} // wdt_test

