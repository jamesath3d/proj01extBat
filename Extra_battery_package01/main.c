
#include "main.h"



static uint8_t _mIdx ;
static uint8_t _mIdx2 ;
int main(void) {


    //uint8_t __ii ;
    //uint8_t __rt ;

    // wdt_test();

    main_init();
    // led_1234_init
    // led_1234_init_all_off();
    // vturnOff3__init
    // _SetOut0Z
    // #define vturnOff3__init()          {_SetOut0Z(pMosGall)}


    //_uart_p1_5_tx_only_testloop();
    while(0){
        if ( 0 == _mIdx2 -- ) {
            _mIdx2 = 32 ;
            #define cMosG3 2,3
            _UART_P1_5_TX_PUT_CH(_Port(cMosG3) + '0');
            _UART_P1_5_TX_PUT_CH(' ');
            _UART_P1_5_TX_PUT_CH(_Pin(cMosG3) + '0');
            _UART_P1_5_TX_PUT_CH(' ');
            _uart_p1_5_tx_only_put_u8( _mIdx ++ );
            _uart_p1_5_tx_only_put_rn();
        }
        _WDT_wait_interrupt_LPM3 ;
    }

    while(0){
        // led_1234_init_test_once
        led_1234_init_test_loop();
        main_init_test1();
    }

    while(0)
    {
        _WDT_wait_interrupt_LPM3 ;
        led_11_on();
        _WDT_wait_interrupt_LPM3 ;
        led_11_off();
    }

    //Delay_100ms(); // 0.1 second
#define debug_test_usage 0
    while(1)
    {
        //led_1234_init_test_once();
        //_UART_P1_5_TX_PUT_CH_A ; // _UART_P1_5_TX_PUT_CH_A ; _UART_P1_5_TX_PUT_CH_A ;
        if ( 0 == _mIdx2 -- ) {
            _mIdx2 = 32 ;
            _uart_p1_5_tx_only_put_rn();
        }
        //if ( debug_test_usage ) led_13_on();
        
        _WDT_wait_interrupt_LPM3 ;

        //if ( debug_test_usage ) led_13_off();
        //_UART_P1_5_TX_PUT_CH_5 ;
        if ( 3 == _mIdx2 ) {
            _uart_p1_5_tx_only_put_hex_u8( _mIdx++ ) ;
        }

        //led_1_blink_once();

        //key_1_blink_once_on_led3();
        key_1_once_toggle_value_t1();
        vturn_34_follow_key1_once();
        led_34_follow_key1_t1_once();

        led_12_follow_dcdc_status34();

        if ( 1 == _mIdx2 ) {
            adc__loop_once();
        }

        //led_2_blink_once();
        // main_init();
        // wdt_init_60ms

    }
}
