/*
 * main_init.c
 *
 *  Created on: Jan 03, 2022
 *      Author: james@h3dgamma.com
 */

#include "_include_all.h"

void main_init(void){

    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer


    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    //    PMM_unlockLPM5();
    PM5CTL0 &= ~LOCKLPM5;

   __delay_cycles(100000); // 0.1 second
} // main_init
