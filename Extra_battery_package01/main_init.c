/*
 * main_init.c
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

#include "_include_all.h"

void main_init(void){
    // Stop watchdog timer
//#ifndef tt4
//    WDT_A_hold(WDT_A_BASE);
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
//#endif

    //_led_red_set_output();
    //_led_green_set_output();
    // "_led_all.h"
    _LED_red_set_out();
    _LED_green_set_out();

    //_i2c01_init();
    _I2C01_INIT();
    //_i2c_expander01_reset_on();
    //_i2c_expander01_reset_off();
    //_I2C_EXPANDER01_RESET_ON();
    //_I2C_EXPANDER01_RESET_ON();
    _I2C_EXPANDER01_RESET_OFF();

    _uart_p1_5_tx_only_init();

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
//#ifndef tt4
//    PMM_unlockLPM5();
    PM5CTL0 &= ~LOCKLPM5;
//#endif
//#ifdef tt4
//#error 33j13j3j1kkk
//#endif

}
