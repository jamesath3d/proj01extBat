
#include "main.h"




void mainY1(void) { // test led 0 1 2 3 4 5
    for ( uint8_t __ii = 0 ; __ii <=5 ; __ii ++ ) {
        ledB = ledBarr[__ii] ; // for test only
        _uart_p1_5_tx_only_put_u8d( __ii );
        _uart_p1_5_tx_only_put_rn();

        _WDT_wait_interrupt_LPM3x( 32 ) ;
    }
} // mainY1
void mainY2(void) {
    //uint8_t __ii ;
    uint8_t __tickCNT ;
#define __keyActived_default 128
#define BatteryMask         0xFF // every 16 second check once
    //#define BatteryMask         0x1FF // every 32 second check once
    //#define BatteryMask         0x3FF // every 64 second check once
    uint8_t __keyActivedCNT ;
    uint32_t __BatteryVoltageMV ;
    uint32_t __BatteryVoltageMv2 ;
    uint8_t  __batteryLevel ;

    __tickCNT = 0 ;
    __keyActivedCNT = 0 ;
    __BatteryVoltageMV = 0 ;
    __BatteryVoltageMv2 = 0 ;

    ledB = LedBrX ; // for test only

    xHost4_off(); xCharge4_off();
    xHost3_on(); xCharge3_on();

    while( 1 )
    {
        _WDT_wait_interrupt_LPM3 ;

        __tickCNT ++ ;
        if ( 0 == ( __tickCNT & 0xF ) ) {
            if ( 0 ) {
                _uart_p1_5_tx_only_put_u8d( key_1_read() ) ;//             _READbit_(key_1) 
                _UART_P1_5_TX_PUT_CH(',');
            }
            if ( 0 ) {
                _uart_p1_5_tx_only_put_u8d( __keyActivedCNT ) ;//             _READbit_(key_1) 
                _UART_P1_5_TX_PUT_CH(',');
            }

            if ( 0 ) {
                _UART_P1_5_TX_PUT_CH(' ');
                _UART_P1_5_TX_PUT_CH('<');
                _uart_p1_5_tx_only_put_uint32d(  __BatteryVoltageMV ) ;
                _UART_P1_5_TX_PUT_CH('>');
            } // if ( 0 == _BatteryChangeCnt ) 

            if ( 0 ) {
                _uart_p1_5_tx_only_put_u8d( __tickCNT >> 4 );
                _uart_p1_5_tx_only_put_rn();
            }

            // interupt_timer0_a0_isr

            if ( 1 ) {
                if ( (__tickCNT & 0x10) ) {
                    interupt_init_ccr1_for_led_off();
                } else {
                    if ( 0 == __keyActivedCNT ) {
                        interupt_init_ccr1_for_led_off();
                    } else {
                        interupt_init_ccr1_for_led_on();
                    }
                }
            }
        }
        if ( 0 == __keyActivedCNT ) {
            if( 0 == key_1_read() ) {//             _READbit_(key_1) 
                __keyActivedCNT = __keyActived_default ;
            }
        } else {
            __keyActivedCNT -- ;
        }
        //if ( 0x1F == ( __tickCNT & 0xFF ) ) { // check every 16 second , stop charger
        if ( 0x0F == ( __tickCNT & BatteryMask ) ) { // check every 16 second , stop charger
            xCharge3_off(); 
        }
        if ( 0x1D == ( __tickCNT & BatteryMask ) ) { // adc read battery 1st
            __BatteryVoltageMv2 = adc__loop_once() ;
        }
        if ( 0x1E == ( __tickCNT & BatteryMask ) ) { // adc read battery 2nd if 1st failed
            if ( 0 == __BatteryVoltageMv2 ) {
                __BatteryVoltageMv2 = adc__loop_once() ;
            }
        }
        if ( 0x1F == ( __tickCNT & BatteryMask ) ) { // restore charger
            if ( 0 == __BatteryVoltageMv2 ) {
                _UART_P1_5_TX_PUT_CH('=');
            } else {
                __batteryLevel =
                    battery_mv_calc_led( __BatteryVoltageMv2 );
                ledB = ledBarr[__batteryLevel] ;

                __BatteryVoltageMV = __BatteryVoltageMv2  ;
                if ( 1 ) {
                    _uart_p1_5_tx_only_put_uint32d(  __BatteryVoltageMv2 ) ;
                    _uart_p1_5_tx_only_put_u8d(  __batteryLevel ) ;
                    _uart_p1_5_tx_only_put_u8d(  ledB ) ;
                    //_UART_P1_5_TX_PUT_CH(',');
                }
            }
            _uart_p1_5_tx_only_put_rn();
            xCharge3_on(); 
        }
    }
    } // mainY2

    int main(void) {


        if(0) mainX2();
        if(0) mainX3();
        if(0) mainX4();
        //while(1);

        main_init();
        //led_1234_init_test_once_all_by_lpm(); // to indicate that the board is actived.

        if(0) main_init_test2_test_flash_evry_gap();
        if(0) main_init_test3_test_flash_evry_16_gap();

        if(0) mainX5();                         // interupt_timer0_a0_isr
        if(0) mainX6();                         // interupt_timer0_a0_isr

        if(1) mainY1();                         // interupt_timer0_a0_isr
        if(1) mainY2();                         // interupt_timer0_a0_isr

        //_Y1( LED_on,        led13 );
        _WDT_wait_interrupt_LPM3_loop;
        //while(1){ _WDT_wait_interrupt_LPM0; }

    }
