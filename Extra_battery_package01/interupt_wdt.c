

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

    if ( _wdt_cnt01 >> 0 ) {
        _wdt_cnt01 = 0  ;
        //_BIC_SR_IRQ(CPUOFF);
    }

    SFRIFG1 &= ~WDTIFG;
    //_BIC_SR_IRQ(LPM4_bits);
    LPM4_EXIT;
}

/* WDT is clocked by fACLK (assumed 32KHz) */
//#define WDT_ADLY_1000       (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0)                /* 1000ms   */
//#define WDT_ADLY_250        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS0)         /* 250ms    */
//#define WDT_ADLY_16         (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS1)         /* 16ms     */
//#define WDT_ADLY_1_9        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS1+WDTIS0)  /* 1.9ms    */
/* WDT is clocked by VLO (assumed 10KHz) */
#define WDT_VLO_30ms517    (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO)                /* 30.517ms   */
#define WDT_VLO_7ms629     (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO+WDTIS0)         /* 7.629ms    */
#define WDT_VLO_ms488      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO+WDTIS1)         /* 0.488us    */

void wdt_init(void) {

    //WDTCTL = WDT_MDLY_32 ;
    //WDTCTL = WDT_MDLY_8 ;
    WDTCTL = WDT_VLO_7ms629 ;
    SFRIE1   |= WDTIE ; // enable WDT interrupt 

    _clk_to_8192 ;
    //_clk_to_16384 ;
    //_clk_to_32768 ;

    _gpio_enable ;
} // wdt_init

void wdt_test(void) {

    wdt_init();

    P1DIR    |= BIT6 ;

    while( 1 ){
        //_BIS_SR( CPUOFF + GIE ) ;
        //_BIS_SR( LPM0_bits + GIE ) ;
        //_BIS_SR( LPM1_bits + GIE ) ;
        //_BIS_SR( LPM2_bits + GIE ) ;
        _BIS_SR( LPM3_bits + GIE ) ;
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

