

#include "main.h"

void wdt_test_with_lpm(void) {
    static uint8_t __wdt_cnt01 ;

    __wdt_cnt01 = 0 ;

    _wdt_timer_gap_60ms_at_1Mhz_main_clk();
    //_wdt_stop ; _gpio_enable ;

    led_1234_init_all_off() ;
    //led_1234_init_test_loop();

    while( 1 ){

        _WDT_wait_interrupt_LPM3;

        __wdt_cnt01 ++;
        //__delay_cycles(1); 
        //__delay_cycles(10); 
        //__delay_cycles(100); 
        //__delay_cycles(1000);
        if (( __wdt_cnt01 & 0x0f )<= 1 ) {
            _Y1( LED_on,    led11 );
        } else {
            _Y1( LED_off,    led11 );
        }


    }
} // wdt_test_with_lpm

void wdt_test_without_lpm(void) {
    static uint8_t __wdt_cnt02 ;

    __wdt_cnt02 = 0 ;

    //_wdt_timer_gap_60ms_at_1Mhz_main_clk();
    _wdt_stop ; _gpio_enable ;

    //P1DIR    |= BIT6 ;
    led_1234_init_all_off() ;
    //led_1234_init_test_loop();

    while( 1 ){

        __wdt_cnt02 ++;
        __delay_cycles(1); 
        __delay_cycles(10); 
        //__delay_cycles(100); 
        //__delay_cycles(1000);
        if ( __wdt_cnt02 <= 1 ) {
        //if ( __wdt_cnt02 <= 100 ) {

            _Y1( LED_on,    led11 );
        } else {
            _Y1( LED_off,    led11 );
        }


    }

} // wdt_test_without_lpm

