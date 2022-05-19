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

void main_init_test2_test_flash_evry_gap(void){
    while(1)
    {
        _WDT_wait_interrupt_LPM3 ;
        led_1234_init_test_once_only();
    }
} // main_init_test2_test_flash_evry_gap

void main_init_test3_test_flash_evry_16_gap(void){
    while(1)
    {
        for ( uint8_t ii=16 ; ii >=1 ; ii -- ) {
            _WDT_wait_interrupt_LPM3 ;
        }
        led_1234_init_test_once_only();

    }
} // main_init_test3_test_flash_evry_16_gap

void main_init(void){

    _wdt_timer_gap_60ms_at_1Mhz_main_clk();
    //_wdt_timer_gap_1000ms_at_1Mhz_main_clk();
    //main_init_test2_test_flash_evry_gap();
    //main_init_test3_test_flash_evry_16_gap();

    _gpio_init();

    led_1234_init_all_off();

    _uart_p1_5_tx_only_init();

    key_1_init();
    vin16_init();

    dcdc_state__init();

    vturn__init();

    adc__init();

    interupt_init_ccr1_for_led_brightness();

    //main_init_test2_test_flash_evry_gap();
    //main_init_test3_test_flash_evry_16_gap();

} // main_init
