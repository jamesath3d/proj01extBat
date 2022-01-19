

#include "main.h"

//uint8_t _wdt_cnt01 ;
    __attribute__((interrupt(WDT_VECTOR)))
void _interupt_wdt_isr(void)
{
    SFRIFG1 &= ~WDTIFG;
    //_BIC_SR_IRQ(CPUOFF);
    //_BIC_SR_IRQ(LPM4_bits);
    LPM3_EXIT;
} // _interupt_wdt_isr

