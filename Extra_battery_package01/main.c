
#include "main.h"


void main_test(void) {

    WDTCTL = WDT_MDLY_32 ;
    //WDTCTL = WDT_MDLY_8 ;
    SFRIE1   |= WDTIE ;

    P1DIR    |= BIT6 ;
    
    while( 1 ){
        //_BIS_SR( CPUOFF + GIE ) ;
        //_BIS_SR( LPM0_bits + GIE ) ;
        //_BIS_SR( LPM1_bits + GIE ) ;
        //_BIS_SR( LPM2_bits + GIE ) ;
        //_BIS_SR( LPM3_bits + GIE ) ;
        _BIS_SR( LPM4_bits + GIE ) ;
        // LPM0; // if no GIE, WDT don't work.

        //P1OUT ^= BIT6 ;
        extern uint8_t _wdt_cnt01 ;
        if ( _wdt_cnt01 != 1 ) {
            P1OUT |= BIT6 ;
        } else {
            P1OUT &= ~BIT6 ;
        }

            //__delay_cycles(1000000);
            //__delay_cycles(3000000);
        }

    } // main_test


    int main(void) {


        uint8_t __ii ;
        uint8_t __rt ;

        main_test();

        main_init();


        // led_1234_init_test_loop();
        // _uart_p1_5_tx_only_testloop();

        led_1234_init_test_loop();

        Delay_100ms(); // 0.1 second

        while(1)
        {
            led_1234_init_test_once();
        }



    }
