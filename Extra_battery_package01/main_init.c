/*
 * main_init.c
 *
 *  Created on: Jan 03, 2022
 *      Author: james@h3dgamma.com
 */

#include "main.h"

void main_init_test(void){
    __delay_cycles(100000); // 0.1 second
}

void main_init(void){

    
    led_1234_init();
    _clk_init_1mhz();

    __delay_cycles(100000); // 0.1 second

    main_init_test();

} // main_init
