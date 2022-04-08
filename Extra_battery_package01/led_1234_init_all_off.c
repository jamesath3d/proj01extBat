
#include "main.h"

void led_1234_init_all_off(void){

    led_1234_init();

    led_1234_init_test_by_byte( 0x00 ) ;
} // led_1234_init_all_off

