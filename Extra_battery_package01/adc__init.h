
#ifndef _ADC__INIT_H
#define _ADC__INIT_H

#define adc_state3_PORT_       2
#define adc_state3_PIN_        0
#define adc_state3in_init()    _SetIN_pullUP( adc_state3 ) 
#define adc_state3in_read()    _READbit_(adc_state3) 

void adc__init(void) ;

#endif
