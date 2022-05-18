
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

int main(void) {


    if(0) mainX2();
    if(0) mainX3();
    if(0) mainX4();
    //while(1);

    main_init();
    //led_1234_init_test_once_all_by_lpm(); // to indicate that the board is actived.

    if(0) mainX5();                         // interupt_timer0_a0_isr
    if(1) mainX6();                         // interupt_timer0_a0_isr

    //_Y1( LED_on,        led13 );
    _WDT_wait_interrupt_LPM3_loop;
    //while(1){ _WDT_wait_interrupt_LPM0; }

    main_init_test2_test_flash_evry_gap();
    main_init_test3_test_flash_evry_16_gap();
}
