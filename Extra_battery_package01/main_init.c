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

    led_1234_init_all_off();

    key_1_init();

} // main_init
