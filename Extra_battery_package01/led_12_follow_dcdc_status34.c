
#include "main.h"

//extern uint8_t _key_1_value_t1 ;

static uint8_t led_12_follow_dcdc_status34_idx = 0 ;
void led_12_follow_dcdc_status34X(void)
{

    led_12_follow_dcdc_status34_idx ++;
    if ( led_12_follow_dcdc_status34_idx >= 16 ) { // every 16 cycle : 16ms * 1
        led_12_follow_dcdc_status34_idx = 0;

        //if ( _key_1_value_t1 ) {
        if ( dcdc_state3in_read() ) {
            led_11_on();
        } else {
            led_11_off();
        }

        if ( dcdc_state4in_read() ) {
            led_12_on();
        } else {
            led_12_off();
        }

        __delay_cycles(1); //__delay_cycles(1000);
        led_11_off();
        led_12_off();
    }
} // led_12_follow_dcdc_status34

void led_12_follow_dcdc_status34(void){

        if ( dcdc_state3in_read() ) {
            //led_11_off();
        } else {
            led_11_on();
            led_11_off();
        }

        if ( dcdc_state4in_read() ) {
            //led_12_off();
        } else {
            led_12_on();
            led_12_off();
        }

} // led_12_follow_dcdc_status34

