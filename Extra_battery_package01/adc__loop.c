
#include "main.h"

void adc__loop_once(void) {
    // ADCCTL0 = ADCSC                  /* ADC Start Conversion */
    //           ADCENC                 /* ADC Enable Conversion */
    //           ADCON                  /* ADC On/enable */

    /* 
     * ADCCTL0 : ADCON        -> 1
     * ADCMCTL0 : ADCINCH_1    -> channel A1
     *
     *   ADCCTL1 : ADCSHS0 , ADCSHS1 -> 0,0
     * & ADCCTL0 : ADCENC   raising up or ADCENC == 1
     * & ADCCTL0 : ADCSC    raising up
     *   So ==> ADCSC raising up is the start enable
     *
     * after ADCSC & ADCENC rasing up, the intel-counter-SAMPCON(sampleCounter) is started.
     * it will run 16 CLK ( set by the ADCSHT_1??? ).
     * Then , SAMPCON FallDown, and the ADC convert start, in 10 + 2 == 12 clk.
     * Then: 1. the result will be save to 16bit register ADCMEM0 
     *       2. ADCIFG0 will be set : 
     *          ADCIFG0 is automatically reset by reading the
     *          ADCMEM0 register or may be reset with software
     *          so , it can be used to detect busy.
     */

    if ( 2 == 3 ) {
        _UART_P1_5_TX_PUT_CH('<');
        _uart_p1_5_tx_only_put_uint16( ADCIFG ) ;
        _UART_P1_5_TX_PUT_CH('>');
    }

} // adc__loop_once
