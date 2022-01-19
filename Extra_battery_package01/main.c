
#include "main.h"



int main(void) {


    //uint8_t __ii ;
    //uint8_t __rt ;

    // wdt_test();

    main_init();


    // led_1234_init_test_loop();
    // _uart_p1_5_tx_only_testloop();

    //led_1234_init_test_loop();

    //Delay_100ms(); // 0.1 second

    while(1)
    {
        //led_1234_init_test_once();
        _WDT_wait_interrupt ;

        //led_1_blink_once();

        //key_1_blink_once_on_led3();
        key_1_once_toggle_value_t1();
        led34_follow_key1_once();

        //led_2_blink_once();

    }
}
