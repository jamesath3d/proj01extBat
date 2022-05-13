
#ifndef _MAIN_H
#define _MAIN_H

#define Clk1mhz

#include "_include_all.h"
#include "led__init.h"
#include "key__init.h"
#include "adc__init.h"
#include "dcdc__init.h"
#include "vturn__init.h"
#include "interupt_wdt.h"
#include "battery_voltage_calc.h"
#include "test01.h"

void main_init_test1(void);
void main_init_test2(void);
void main_init_test3(void);

#endif
