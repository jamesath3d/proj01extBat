

#include "main.h"

//uint8_t _wdt_cnt01 ;
    __attribute__((interrupt(WDT_VECTOR))) // 0x48 --> 0xffe6
void interupt_wdt_isr(void)
{
    //_Y1( LED_flash,        led14 ); 

    SFRIFG1 &= ~WDTIFG;
    //_BIC_SR_IRQ(CPUOFF);
    //_BIC_SR_IRQ(LPM4_bits);
    LPM3_EXIT;
} // _interupt_wdt_isr

