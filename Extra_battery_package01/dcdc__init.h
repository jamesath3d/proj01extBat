
#ifndef _DCDC__INIT_H
#define _DCDC__INIT_H

#define dcdc_state3_PORT_       2
#define dcdc_state3_PIN_        6
#define dcdc_state3in_init()    _SetIN_pullUP( dcdc_state3 ) 
#define dcdc_state3in_read()    _READbit_(dcdc_state3) 

#define dcdc_state4_PORT_       2
#define dcdc_state4_PIN_        1
#define dcdc_state4in_init()    _SetIN_pullUP( dcdc_state4 ) 
#define dcdc_state4in_read()    _READbit_(dcdc_state4) 


void dcdc_state__init(void) ;

//        dcdc_state3_read

#endif
