/*
 * main_init.c
 *
 *  Created on: Jan 03, 2022
 *      Author: james@h3dgamma.com
 */

#include "main.h"

void main_init_test(void){
    led_1234_init_test_loop();
}

void main_init(void){

    //ClkInit();
    //wdt_init_60ms();
    _WDT_init ;

    _gpio_init();

    led_1234_init_all_off();

    _uart_p1_5_tx_only_init();

    key_1_init();

    dcdc__init();

    vturn__init();

    adc__init();

} // main_init
