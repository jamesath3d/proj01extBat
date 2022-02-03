
#include "main.h"

static uint8_t adc_i8 = 0 ;
static uint32_t adc_i16 = 0 ;
static uint32_t adc_i32 = 0 ;
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

    // adc__init();
    if ( ( ADCCTL0 & ADCSC ) && ( ADCCTL1 & ADCBUSY ) ) { // if a convert is started , and busy
        ADCCTL0 &= ~ADCSC; // FallDown ADCSC
        adc_i8 ++ ;
    }

    if ( 1 && ( ADCIFG & ADCIFG0 )) {
        if ( 1 ) {
            adc_i16 = ADCMEM0 ; 
            _uart_p1_5_tx_only_put_uint16( adc_i16 ) ; 
            //adc_i32 = 3300 * adc_i16 / 0x3FF ; 
            adc_i32 = 3300 * adc_i16 / 0x400 ; 

            _uart_p1_5_tx_only_put_uint16d( adc_i32 ) ; 
            //_uart_p1_5_tx_only_put_uint16d( adc_i32 * 502/100) ; 
            _uart_p1_5_tx_only_put_uint16d( adc_i32 * 12/2) ; 
        } else {
            _uart_p1_5_tx_only_put_uint16( ADCMEM0 ) ; 
        }

    }
    if ( 0 == ( ADCCTL0 & ADCSC ) // if NO convert is started 
            && 0 == ( ADCCTL1 & ADCBUSY ) // if UN-busy
            && 0 == ( ADCIFG & ADCIFG0 )  // if data in ADCMEM0 has been read.
       ) { 
        ADCCTL0 |= ADCSC; // start a NEW convert
    }
} // adc__loop_once


