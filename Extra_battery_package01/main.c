
#include "main.h"



void mainX2(void) {
    while ( 1 ) {
        _wdt_stop ; _gpio_enable ;
        led_1234_init_all_off() ;
        led_1234_init_test_loop();
    } 
} // mainX2
void mainX3(void) {
    while ( 1 ) {
        wdt_test_with_lpm();
        //wdt_test_without_lpm();
    }
} // mainX3
void mainX4(void) {
    // led_1234_init
    // led_1234_init_all_off();
    // vturn__init();
    // vturnOff3__init
    // _SetOut0Z
    // #define vturnOff3__init()          {_SetOut0Z(pMosGall)}


    //_uart_p1_5_tx_only_testloop();
    _Y1( LED_on,    led14 );

    if ( 0 ) mtest01_test_uart();
    if ( 0 ) mtest02_test_led_test_loop();
    if ( 0 ) mtest03_test_wdt_as_timer_gap();
    if ( 0 ) mtest04_test_led_loop_16_gap();
    if ( 0 ) mtest05_test_led_flash_one_clk();
    if ( 0 ) mtest06();
    if ( 0 ) mtest07();
#ifdef xxx2
#endif // xxx2

    if ( 0 ) mtest99();

    //if ( 1 ) mtest03_test_wdt_as_timer_gap();
    mtest100_led_by_delay();
} // mainX4

void mainX5(void) {
    //uint8_t __ii ;
    uint8_t __jj ;
    uint8_t __kk ;
    __kk = 0 ;
    while( 1 )
    {
        for ( uint8_t __ii = 16 ; __ii >= 1 ; __ii -- ) { _WDT_wait_interrupt_LPM3 ; }
        //_WDT_wait_interrupt_LPM3 ;
        __kk ++ ;
        __jj = __kk % 6 ;

        if ( 2 == __jj ) {
            interupt_init_ccr1_for_led_off();
            //interupt_init_ccr1_for_led_brightness();
        }
        if ( 3 == __jj ) {
            interupt_init_ccr1_for_led_on();
            //interupt_init_ccr1_for_led_brightness();
        }

        ledB = ledBarr[ __jj ] ; 
        // interupt_timer0_a0_isr

        _uart_p1_5_tx_only_put_u8d( __jj );
        _uart_p1_5_tx_only_put_rn();

        _WDT_wait_interrupt_LPM3 ;
    }
} // mainX5

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
