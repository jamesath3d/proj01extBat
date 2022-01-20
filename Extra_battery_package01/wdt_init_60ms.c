

#include "main.h"

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


    _clk_to_8192 ; // when VLO_60ms, 55ms WDT, 980us on/off // total 13.5ms,24%
    //_clk_to_16384 ; // when VLO_60ms, 55ms WDT, 480us on/off
    //_clk_to_32768 ; // when VLO_60ms, 55ms WDT, 240us on/off // total 3.25ms,6%

    _gpio_enable ;

    SFRIE1   |= WDTIE ; // enable WDT interrupt 
} // wdt_init_60ms

