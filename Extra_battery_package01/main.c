
#include "main.h"




void mainX6(void) {
    //uint8_t __ii ;
    uint16_t __tickCNT ;
    uint16_t __jj ;
    uint8_t  __kk ;
    __tickCNT = 0 ;
    while( 1 )
    {
        __tickCNT ++ ;
        //_WDT_wait_interrupt_LPM3 ;
        __jj = __tickCNT >> 5 ;  // 2 second
        __kk = __jj % 6 ; 

        ledB = ledBarr[ __kk ] ; 
        //ledB = LedBr3 ; // for test only

        if ( (__tickCNT & 0x10) ) {
            interupt_init_ccr1_for_led_off();
        } else {
            interupt_init_ccr1_for_led_on();
        }

        // interupt_timer0_a0_isr

        if ( 0 == ( __tickCNT & 0xF ) ) {
            _uart_p1_5_tx_only_put_u8d( __kk );
            _uart_p1_5_tx_only_put_rn();
        }

        _WDT_wait_interrupt_LPM3 ;
    }
} // mainX6
void mainY1(void) {
    //uint8_t __ii ;
    uint8_t __tickCNT ;
#define __keyActived_default 128
    uint8_t __keyActivedCNT ;
    __tickCNT = 0 ;
    __keyActivedCNT = 0 ;

    ledB = LedBr3 ; // for test only
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

            _uart_p1_5_tx_only_put_u8d( __tickCNT >> 4 );
            _uart_p1_5_tx_only_put_rn();

            // interupt_timer0_a0_isr

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
        if ( 0 == __keyActivedCNT ) {
            if( 0 == key_1_read() ) {//             _READbit_(key_1) 
                __keyActivedCNT = __keyActived_default ;
            }
        } else {
            __keyActivedCNT -- ;
        }

    }
} // mainY1

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

    //_Y1( LED_on,        led13 );
    _WDT_wait_interrupt_LPM3_loop;
    //while(1){ _WDT_wait_interrupt_LPM0; }

}
