
#include "main.h"

void led_1234_init_test_loop(void){
    while ( 1 ) {
        __delay_cycles(100000);  // 0.1 second
        __delay_cycles(1000000); // 1   second
        led_14_on()             ;

        __delay_cycles(100000); // 0.1 second
        //__delay_cycles(1000000); // 1   second
        led_14_off()            ;
    }
}

void led_1234_init(void){
    led_14_set_out();
}
