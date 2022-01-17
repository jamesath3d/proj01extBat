

#include "main.h"

    __attribute__((interrupt(TIMER0_A0_VECTOR)))
void _timer0_a0_isr(void)
{

} // timer0_a0_isr

uint8_t _wdt_cnt01 ;
    __attribute__((interrupt(WDT_VECTOR)))
void _wdt_isr(void)
{
    _wdt_cnt01 ++ ;

    if ( _wdt_cnt01 >> 5 ) {
        _wdt_cnt01 = 0  ;
        //_BIC_SR_IRQ(CPUOFF);
    }

    SFRIFG1 &= ~WDTIFG;
    //_BIC_SR_IRQ(LPM4_bits);
    LPM4_EXIT;
}

void wdt_test(void) {

    WDTCTL = WDT_MDLY_32 ;
    //WDTCTL = WDT_MDLY_8 ;
    SFRIE1   |= WDTIE ;

    P1DIR    |= BIT6 ;

    _clk_to_8192 ;
    //_clk_to_16384 ;
    //_clk_to_32768 ;
    _gpio_enable ;

    while( 1 ){
        //_BIS_SR( CPUOFF + GIE ) ;
        _BIS_SR( LPM0_bits + GIE ) ;
        //_BIS_SR( LPM1_bits + GIE ) ;
        //_BIS_SR( LPM2_bits + GIE ) ;
        //_BIS_SR( LPM3_bits + GIE ) ;
        //_BIS_SR( LPM4_bits + GIE ) ;
        // LPM0; // if no GIE, WDT don't work.

        P1OUT &= ~BIT6 ; // on
        __delay_cycles(1); //__delay_cycles(1000);
        P1OUT |= BIT6 ; // off

        /*
           extern uint8_t _wdt_cnt01 ;
           if ( _wdt_cnt01 != 1 ) {
           P1OUT |= BIT6 ;
           } else {
           P1OUT &= ~BIT6 ;
           }

        //__delay_cycles(1000000);
        //__delay_cycles(3000000);
        */
    }

} // wdt_test

