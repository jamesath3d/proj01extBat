
#include "main.h"



int main(void) {


    //uint8_t __ii ;
    //uint8_t __rt ;

    wdt_test();

    main_init();
    main_init_test2_test_flash_evry_gap();
    main_init_test3_test_flash_evry_16_gap();
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
}
