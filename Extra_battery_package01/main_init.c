/*
 * main_init.c
 *
 *  Created on: Jan 03, 2022
 *      Author: james@h3dgamma.com
 */

#include "main.h"

void main_init_test(void){
    //__delay_cycles(100000); // 0.1 second
    led_1234_init_test_loop();
}

void main_init(void){

    _clk_init_1mhz();

    led_1234_init();

    __delay_cycles(100000); // 0.1 second

    main_init_test();

} // main_init
