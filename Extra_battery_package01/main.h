
#ifndef _MAIN_H
#define _MAIN_H

#include "_include_all.h"
#include "led__init.h"
#include "key__init.h"
#include "adc__init.h"
#include "dcdc__init.h"
#include "vturn__init.h"
#include "interupt_wdt.h"

#define Clk16384

#ifdef  Clk16384
#define ClkInit()       _clk_init_16384()
#define Delay_1000ms()  __delay_cycles(16384)  //  1000 ms
#define Delay_100ms()   __delay_cycles(1638)   //  100  ms
#define Delay_10ms()    __delay_cycles(163)    //  10   ms
#define Delay_1ms()     __delay_cycles(16)     //  1    ms
#endif

#endif
