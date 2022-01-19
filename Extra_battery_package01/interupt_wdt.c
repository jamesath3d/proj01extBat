

#include "main.h"

    __attribute__((interrupt(TIMER0_A0_VECTOR)))
void _timer0_a0_isr(void)
{

} // timer0_a0_isr

uint8_t _wdt_cnt01 ;
    __attribute__((interrupt(WDT_VECTOR)))
void _wdt_isr(void)
{
    SFRIFG1 &= ~WDTIFG;
    //_BIC_SR_IRQ(CPUOFF);
    //_BIC_SR_IRQ(LPM4_bits);
    LPM3_EXIT;
}

void wdt_init_60ms(void) {

    //WDTCTL = WDT_MDLY_32 ;
    //WDTCTL = WDT_MDLY_8 ;
    //WDTCTL = WDT_ADLY_1000 ;
    //WDTCTL = WDT_ADLY_250 ;
    //WDTCTL = WDT_ADLY_16 ;
    //WDTCTL = WDT_VLO_4200ms ;
    //WDTCTL = WDT_VLO_1050ms ;
    WDTCTL = WDT_VLO_60ms ;
    //WDTCTL = WDT_VLO_7ms1 ;


    _clk_to_8192 ;
    //_clk_to_16384 ;
    //_clk_to_32768 ;

    _gpio_enable ;

    SFRIE1   |= WDTIE ; // enable WDT interrupt 
} // wdt_init_60ms

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

//void led_1_blink_once(void){
