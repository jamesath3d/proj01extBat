
#include "main.h"


void mtest01_test_uart(void){
    int32_t ___ii ;
    ___ii = 0 ;
    while(1){
        if ( 0 >= ___ii -- ) {
            ___ii = 32 ;
#define cMosG3 2,3
            _UART_P1_5_TX_PUT_CH(_Port(cMosG3) + '0');
            _UART_P1_5_TX_PUT_CH(' ');
            _UART_P1_5_TX_PUT_CH(_Pin(cMosG3) + '0');
            _UART_P1_5_TX_PUT_CH(' ');
            _uart_p1_5_tx_only_put_u8d( ___ii ++ );
            _uart_p1_5_tx_only_put_rn();
        }
        _WDT_wait_interrupt_LPM3 ;
    }
} // mtest01_test_uart
void mtest02_test_led_test_loop(void){
    while(1){
        // led_1234_init_test_once
        led_1234_init_test_loop();
        main_init_test1();
    }
} // mtest02_test_led_test_loop
void mtest03_test_wdt_as_timer_gap(void){
    while(1)
    {
        _WDT_wait_interrupt_LPM3 ;
        //led_11_on();
        _Y1( LED_on,    led11 );
        _WDT_wait_interrupt_LPM3 ;
        _Y1( LED_off,   led11 );
    }
} // mtest03_test_wdt_as_timer_gap
void mtest04_test_led_loop_16_gap(void){
    while( 1 )
    {
        for ( int16_t __ii = 16 ; __ii >= 1 ; __ii -- ) {
            _WDT_wait_interrupt_LPM3 ;
        }
        _Y1( LED_on,   led14 ); 
        _WDT_wait_interrupt_LPM3 ;
        _Y1( LED_off,   led14 ); 

    }
} // mtest04_test_led_loop_16_gap
void mtest05_test_led_flash_one_clk(void){
    while( 1 )
    {
        _WDT_wait_interrupt_LPM3 ;

        _Y1( LED_on,   led14 ); 
        //_WDT_wait_interrupt_LPM3 ;
        _Y1( LED_off,   led14 ); 

    }
} // mtest05_test_led_flash_one_clk
