
#ifndef _KEY__INIT_H
#define _KEY__INIT_H

//#define key_1_PORT_             2
//#define key_1_PIN_              3
//#define key_1_init()            _SetIN_pullUP( key_1 ) 
//#define key_1_read()            _READbit_(key_1) 

#define key_1               2,3
#define key_1_init()        _Y1( _PinitAsInRenOffX,  key_1 ) 
#define key_1_read()        _R1( _READbitX, key_1 )  

#define vin16               1,6
#define vin16_init()        _Y1( _PinitAsInRenOffX,  vin16 ) 
#define vin16_read()        _R1( _READbitX, vin16 )  


void key_1_blink_once_on_led3(void);
void key_1_once_toggle_value_t1(void);
void led_34_follow_key1_t1_once(void);

#endif
