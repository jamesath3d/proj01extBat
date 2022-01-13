

#include "main.h"

__attribute__((interrupt(TIMER0_A0_VECTOR)))
void _timer0_a0_isr(void)
{

} // timer0_a0_isr

static uint8_t _wdt_cnt01 ;
__attribute__((interrupt(WDT_VECTOR)))
void _wdt_isr(void)
{
    _wdt_cnt01 ++ ;
    //if ( _wdt_cnt01 >= 32 ) {
    if ( _wdt_cnt01 >= 64 ) {
        _wdt_cnt01 = 0  ;
        _BIC_SR_IRQ(CPUOFF);
    }

}
