
#include "main.h"

//extern uint8_t _key_1_value_t1 ;

//        _Y1( LED_on,    led11 );
//        _Y1( LED_off,   led11 );

static uint8_t led_12_follow_dcdc_status34_idx = 0 ;
void led_12_follow_dcdc_status34X(void)
{

    led_12_follow_dcdc_status34_idx ++;
    if ( led_12_follow_dcdc_status34_idx >= 16 ) { // every 16 cycle : 16ms * 1
        led_12_follow_dcdc_status34_idx = 0;

        //if ( _key_1_value_t1 ) {
        if ( dcdc_state3in_read() ) {
            _Y1( LED_on,    led11 );
        } else {
            _Y1( LED_off,   led11 );
        }

        if ( dcdc_state4in_read() ) {
            _Y1( LED_on,   led12 );
        } else {
            _Y1( LED_off,   led12 );
        }

        __delay_cycles(1); //__delay_cycles(1000);
        _Y1( LED_off,   led11 );
        _Y1( LED_off,   led12 );
    }
} // led_12_follow_dcdc_status34

void led_12_follow_dcdc_status34(void){

        if ( dcdc_state3in_read() ) {
            //_Y1( LED_off,   led11 );
        } else {
            _Y1( LED_on,    led11 );
            __delay_cycles(200); // 10us @ mclk 1Mhz
            _Y1( LED_off,   led11 );
        }

        if ( dcdc_state4in_read() ) {
            //_Y1( LED_off,   led12 );
        } else {
            _Y1( LED_on,   led12 );
            __delay_cycles(200); // 10us @ mclk 1Mhz
            _Y1( LED_off,   led12 );
        }

} // led_12_follow_dcdc_status34

