
#include "main.h"




void mainY1(void) { // test led 0 1 2 3 4 5
    for ( uint8_t __ii = 0 ; __ii <=7 ; __ii ++ ) {
        ledB = _ledLevel_calc_ledIO(__ii) ; // for test only
        _uart_p1_5_tx_only_put_u8d( __ii );
        _uart_p1_5_tx_only_put_rn();

        _WDT_wait_interrupt_LPM3x( 32 ) ;
    }
} // mainY1
void mainY2(void) {
    //uint8_t __ii ;
    uint8_t __tickCNT ;
    uint8_t __roundCNT ;
#define __keyActived_default 128
#define BatteryMask         0xFF // every 16 second check once
    //#define BatteryMask         0x1FF // every 32 second check once
    //#define BatteryMask         0x3FF // every 64 second check once
    uint8_t __keyActivedCNT ;
    uint32_t __BatteryVoltageMV_last ;
    uint32_t __BatteryVoltageMv2 ;
    uint8_t  __batteryLevel ;

    __batteryLevel = 0 ;
    __tickCNT = 0 ;
    __roundCNT = 0 ;
    __keyActivedCNT = 0 ;
    __BatteryVoltageMV_last = 0 ;
    __BatteryVoltageMv2 = 0 ;

    ledB = LedBrX ; // for test only

    //xHost4_off(); 
    //xCharge4_off();
    //xHost3_on(); 
    xCharge3_on();
    xLedBlueGreenOff();

    while( 1 )
    {
        _WDT_wait_interrupt_LPM3 ;

        __tickCNT ++ ;

        // every 0x10(gap 1 second), check : if vin16_read() getting high, always on;
        // if vin16 is low, LED only on if __keyActivedCNT is NOT zero.
        if ( 0 == ( __tickCNT & 0xF ) ) {
            // interupt_timer0_a0_isr

            if ( 1 ) { // deal with flash time : end
                if ( (__tickCNT & 0x10) ) { // odd second : off
                    if ( __batteryLevel == 7 ) { // 7 : all-full
                        xLedBlueOn();
                    } else {
                        if ( __batteryLevel == 1 ) { // 1 : almost-empty, need charge at once
                            xLedBlueOn();
                        } else {
                            interupt_init_ccr1_for_led_off();
                        }
                    }
                } else {                    // even sencod : if charger inserted, on ; if no charger , only flash 4 second.
                    if ( vin16_read() ) { // charger inserted
                        interupt_init_ccr1_for_led_on();
                    } else { // no charger, battery only, enter power save mode
                        if ( 0 == __keyActivedCNT ) { // power save mode : out of 4 second, turn off
                            interupt_init_ccr1_for_led_off();

                            // if > 9.0v, the 2 minutes flash even though no key.
                            if ( __BatteryVoltageMV_last > 8000 ) { 
                                if ( 0 == (__roundCNT & 0x1F) ) { 
                                    // 0x07 : 16 sec
                                    // 0x1F : 64 sec force led on to show this battary is alive.
                                    interupt_init_ccr1_for_led_on();
                                    _UART_P1_5_TX_PUT_CH('-');
                                }
                            }
                        } else {                      // power save mode : within 4 second, turn on
                            interupt_init_ccr1_for_led_on();
                        }
                    }
                }
                //                if ( (__tickCNT & 0x20) ) {
                //                    xLedBlueOn();
                //                } else {
                //                    xLedGreenOn();
                //                }
            } // deal with flash time : end

            if ( 0 == ( __tickCNT & 0x1F ) ) {
                __roundCNT ++ ;
                //_UART_P1_5_TX_PUT_CH('<');
                switch ( __roundCNT & 3 ) {
                    case 0:
                        xLedBlueGreenOff();
                        //_UART_P1_5_TX_PUT_CH('0');
                        break;
                    case 1:
                        xLedGreenOn();
                        //_UART_P1_5_TX_PUT_CH('1');
                        break;
                    case 2:
                        xLedBlueOn();
                        //_UART_P1_5_TX_PUT_CH('2');
                        break;
                    default:
                        xLedBlueGreenOn();
                        //_UART_P1_5_TX_PUT_CH('3');
                        break;
                }
                xLedGreenOn(); // force Green On
                //_UART_P1_5_TX_PUT_CH('>');
            }
        } // end of whether LED is on

        if (1 == __batteryLevel) {
            if ( 0x3E == (0x3F & __tickCNT ))  {
                _UART_P1_5_TX_PUT_CH('#');
                //__keyActivedCNT = (__keyActived_default>>3) ;
                interupt_init_ccr1_for_led_on();
            }
        }

        if ( 0 == __keyActivedCNT ) {
            if( 0 == key_1_read() ) {//             _READbit_(key_1) 
                __keyActivedCNT = __keyActived_default ;
                interupt_init_ccr1_for_led_on();
            } else {
            }
        } else {
            __keyActivedCNT -- ;
        }
        // from 0x0f to 0x1D/0x1e, stop charger, 0x1F, start charge, 
        // about 0x10 Time Gap equals 1 second. 0xFF about 16 seconds totally
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
                    _battery_mv_calc_ledLevel( __BatteryVoltageMv2 );
                ledB = _ledLevel_calc_ledIO(__batteryLevel) ;

                __BatteryVoltageMV_last = __BatteryVoltageMv2  ;
                if ( 1 ) {
                    _uart_p1_5_tx_only_put_uint32d(  __BatteryVoltageMv2 ) ;
                    _uart_p1_5_tx_only_put_u8d(  __batteryLevel ) ;
                    _uart_p1_5_tx_only_put_str(" 0x");
                    _uart_p1_5_tx_only_put_hex(  ledB ) ;
                    //_UART_P1_5_TX_PUT_CH(',');
                }
            }
            _uart_p1_5_tx_only_put_rn();
            xCharge3_on(); 
        }
    } // while loop
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
