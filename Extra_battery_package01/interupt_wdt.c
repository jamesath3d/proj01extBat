

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

