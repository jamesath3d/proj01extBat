
#include "main.h"



static uint8_t  _mIdx ;
static uint8_t  _mIdx2 ;

#define         _button_pressed_cnt_default      45
static uint8_t  _button_pressed_cnt = _button_pressed_cnt_default;
static uint32_t  _BatteryVoltageMV ;
static uint8_t  _led_calced_by_adc ;
static uint8_t  _led_flash_cnt ;

int main(void) {


    //uint8_t __ii ;
    //uint8_t __rt ;

    // wdt_test();

    main_init();
    // led_1234_init
    // led_1234_init_all_off();
    // vturn__init();
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
        //led_11_on();
        _Y1( LED_on,    led11 );
        _WDT_wait_interrupt_LPM3 ;
        _Y1( LED_off,   led11 );
    }

    vturn_on_3(); xHost3_on();
    //vturn_on_4(); xHost4_on();

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
        if ( 1 && ( 3 == _mIdx2 )) {
            _uart_p1_5_tx_only_put_hex_u8( _mIdx++ ) ;
        }

        //led_1_blink_once();

        //key_1_blink_once_on_led3();
        key_1_once_toggle_value_t1();

        if ( 0 && ( 2 == _mIdx2 )) {
            vturn_34_follow_key1_once();
        }

        if ( 0 ) {
            led_34_follow_key1_t1_once();
            led_12_follow_dcdc_status34();
        }
        if ( 1 ) {
            _led_flash_cnt -- ;
            if ( 1 == (_led_flash_cnt & 0x1) ) {
                led_1234_init_test_by_byte( _led_calced_by_adc );
                __delay_cycles( 300 ) ;
                led_1234_init_test_by_byte( 0 );
            }
        }

        if ( 1 == _mIdx2 ) {
            _BatteryVoltageMV = adc__loop_once() ;
            if ( 0 != _BatteryVoltageMV ) {
                _led_calced_by_adc = battery_mv_calc_led( _BatteryVoltageMV );

                _UART_P1_5_TX_PUT_CH('[');
                _uart_p1_5_tx_only_put_u8d( _led_calced_by_adc ) ;
                _UART_P1_5_TX_PUT_CH(']');
            }

            if ( 0 != _BatteryVoltageMV ) {
                _uart_p1_5_tx_only_put_uint16d( _BatteryVoltageMV ) ;
            }
        }

        //led_2_blink_once();
        // main_init();
        // wdt_init_60ms

    }
}
