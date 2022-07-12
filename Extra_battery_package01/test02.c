
#include "main.h"



static uint8_t  _mIdx ;
static uint8_t  _mIdx2 ;

#define         _button_pressed_cnt_default      45
//static uint8_t  _button_pressed_cnt = _button_pressed_cnt_default;
static uint32_t  _BatteryVoltageMV ;
static uint8_t  _led_calced_by_adc ;
static uint8_t  _led_flash_cnt ;
#define  _BatteryChangeCnt_default  64
#define  _BatteryChangeCnt_test     32   
static uint32_t  _BatteryChangeArr[_BatteryChangeCnt_test] ;
static uint32_t  _BatteryChangeCnt = _BatteryChangeCnt_default ;

//#ifdef disable_main_test
void mtest06(void){
    while ( 1 ) {
        _WDT_wait_interrupt_LPM3 ;
        if ( 0 == _BatteryChangeCnt ) {
            _BatteryChangeCnt = _BatteryChangeCnt_default ;
            _uart_p1_5_tx_only_put_str( "======================\r\n\r\n\r\n" ) ;
        }
        _BatteryChangeCnt -- ;
//         if ( 0 ) {
//             _uart_p1_5_tx_only_put_uint32( _BatteryChangeCnt );
//             _uart_p1_5_tx_only_put_rn();
//         }
//         if ( 0 ) {
//             if ( _BatteryChangeCnt < _BatteryChangeCnt_test ) {
//                 _Y1( LED_on,   led14 ); 
//             } else {
//                 _Y1( LED_off,   led14 ); 
//             }
//         }
        //if ( _BatteryChangeCnt & 1 ) {
            _Y1( LED_on,   led14 ); 
        //} else {
//            _Y1( LED_off,   led14 ); 
 //       }
    }
} // mtest06
void mtest07(void){
    while ( 1) {
        _WDT_wait_interrupt_LPM3 ;
        if ( 0 == _BatteryChangeCnt ) {
            _BatteryChangeCnt = _BatteryChangeCnt_default ;
            _uart_p1_5_tx_only_put_str( "======================\r\n\r\n\r\n" ) ;
        }
        _BatteryChangeCnt -- ;
        if ( 0 ) {
            _uart_p1_5_tx_only_put_uint32( _BatteryChangeCnt );
            _uart_p1_5_tx_only_put_rn();
        }
        if ( 1 ) {
            if ( _BatteryChangeCnt < _BatteryChangeCnt_default ) {
                _Y1( LED_on,   led14 ); 
            } else {
                _Y1( LED_off,   led14 ); 
            }
        }
        if ( 0 ) {
            if ( _BatteryChangeCnt < _BatteryChangeCnt_default ) {
                //xCharge3_off(); xCharge4_off();
                _Y1( LED_on,   led14 ); 
                _BatteryVoltageMV = adc__loop_once() ;
                _BatteryChangeArr[_BatteryChangeCnt] = _BatteryVoltageMV ;
                if ( 0 == _BatteryChangeCnt ) {
                    for ( int16_t __ii = _BatteryChangeCnt_default - 1 ; __ii >= 0 ; __ii -- ) {
                        _UART_P1_5_TX_PUT_CH(' ');
                        _UART_P1_5_TX_PUT_CH('<');
                        _uart_p1_5_tx_only_put_uint16d(  _BatteryChangeArr[ __ii ]  ) ;
                        _UART_P1_5_TX_PUT_CH('>');
                    }
                } // if ( 0 == _BatteryChangeCnt ) 
            }
            else {
                _Y1( LED_off,   led14 ); 
                xCharge3_on(); 
                //xCharge4_off();
            }
        }
    }
} // mtest07
//#endif // disable_main_test

void mtest99(void){
    vturn_on_3(); 
    //xHost3_on();
    //vturn_on_4(); xHost4_on();

    //Delay_100ms(); // 0.1 second
    //main_init_test3();
    
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
        if ( 0 ) {
            _led_flash_cnt -- ;
            if ( 1 == (_led_flash_cnt & 0x1) ) {
                led_1234_init_test_by_byte( _led_calced_by_adc );
                __delay_cycles( 300 ) ;
                led_1234_init_test_by_byte( 0 );
            }
        }

        if ( 0 &&( 1 == _mIdx2 )) {
            _BatteryVoltageMV = adc__loop_once() ;
            if ( 0 != _BatteryVoltageMV ) {
                _led_calced_by_adc = 
                    _battery_mv_calc_ledLevel( _BatteryVoltageMV );

                if ( 1 ) {
                    _UART_P1_5_TX_PUT_CH(' ');
                    _UART_P1_5_TX_PUT_CH('[');
                    _uart_p1_5_tx_only_put_u8d( _led_calced_by_adc ) ;
                    _UART_P1_5_TX_PUT_CH(']');
                }
            }

            if ( 0 != _BatteryVoltageMV ) {
                _uart_p1_5_tx_only_put_uint16d( _BatteryVoltageMV ) ;
            }
        }

        //led_2_blink_once();
        // main_init();
        // wdt_init_60ms

    }
} // mtest99

void mtest100_led_by_delay(void){
    while(1)
    {

        //__delay_cycles( 1000 ) ;
        _Y1( LED_on,    led14 );
        //__delay_cycles( 1000 ) ;
        _Y1( LED_off,   led14 );
    }
} // mtest100_led_by_delay
