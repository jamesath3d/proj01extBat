
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
    TA0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    TA0CCTL2 = OUTMOD_2;                      // CCR2 reset/set
    TA0CCR0 = 32000 ;                         // PWM Period , as the count-up maximum, which is use CCR0
    TA0CCR1 = 3200;                           // CCR1 PWM duty cycle
    TA0CCR2 = 29000;                            // CCR2 PWM duty cycle

    //TA0CTL = TASSEL__SMCLK | MC__UP | TACLR | TAIE | TAIFG ;  // SMCLK, up mode, clear TAR
    TA0CTL = TASSEL__ACLK | MC__UP | TACLR;  // ACLK(32768Hz), up mode, clear TAR
    //TA0CTL = TASSEL__ACLK | MC__UP | TACLR | TAIE;  // ACLK(32768Hz), up mode, clear TAR
} // mainX5

int main(void) {


    if(0) mainX2();
    if(0) mainX3();
    if(0) mainX4();
    //while(1);

    main_init();
    //led_1234_init_test_once_all_by_lpm(); // to indicate that the board is actived.
    if(1) mainX5();                         // _interupt_timer0_a0_isr
    //_Y1( LED_on,        led13 );
    while(1){ _WDT_wait_interrupt_LPM3; }   // _interupt_wdt_isr
    //while(1){ _WDT_wait_interrupt_LPM0; }

    main_init_test2_test_flash_evry_gap();
    main_init_test3_test_flash_evry_16_gap();
}
