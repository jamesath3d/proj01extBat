/*
 * main_init.c
 *
 *  Created on: Jan 03, 2022
 *      Author: james@h3dgamma.com
 */

#include "main.h"

void main_init_test1(void){
    led_1234_init_test_loop();
} // main_init_test1

void main_init_test2(void){
    while(1)
    {
        _WDT_wait_interrupt_LPM3 ;
        led_1234_init_test_once_only();
    }
} // main_init_test2

void main_init(void){

    _wdt_timer_gap_60ms_at_1Mhz_main_clk();

    _gpio_init();

    led_1234_init_all_off();

    _uart_p1_5_tx_only_init();

    key_1_init();

    dcdc_state__init();

    vturn__init();

    //adc__init();

    //main_init_test2();

} // main_init
