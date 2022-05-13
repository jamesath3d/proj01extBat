

#include "main.h"

static uint8_t _wdt_cnt01 = 0 ;
void wdt_test(void) {

    _wdt_timer_gap_60ms_at_1Mhz_main_clk();

    //P1DIR    |= BIT6 ;
    led_1234_init_all_off() ;

    while( 1 ){

        _WDT_wait_interrupt_LPM3 ;

        _wdt_cnt01 ++;
        if ( _wdt_cnt01 >= 16 ) {
            _wdt_cnt01 = 0;

            //P1OUT &= ~BIT6 ; // on
            //__delay_cycles(1); //__delay_cycles(1000);
            //P1OUT |= BIT6 ; // off

            //led_11_on();
            _Y1( LED_on,    led11 );
            __delay_cycles(1); //__delay_cycles(1000);
            //led_11_off();
            _Y1( LED_off,    led11 );
        }


    }

} // wdt_test

