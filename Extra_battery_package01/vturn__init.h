
#ifndef _VTURN__INIT_H
#define _VTURN__INIT_H


//void key_1_blink_once_on_led3(void);
//void key_1_once_toggle_value_t1(void);
//void led_34_follow_key1_once(void);

// p2.3/vturnOff3
#define vturnOff3_PORT_            2
#define vturnOff3_PIN_             3
#define vturnOff3_TO_1()           { _SetIN_(vturnOff3); }     // to 1
#define vturnOff3_TO_0()           { _SetOUT_(vturnOff3); }     // to 0
#define vturnOff3__init()          { _Set0_( vturnOff3 ); }
#define vturnOff3__to_0()          vturnOff3_TO_0()
#define vturnOff3__to_1()          vturnOff3_TO_1()

// p2.2/vturnOff4
#define vturnOff4_PORT_            2
#define vturnOff4_PIN_             2
#define vturnOff4_TO_1()           { _SetIN_(vturnOff4); }     // to 1
#define vturnOff4_TO_0()           { _SetOUT_(vturnOff4); }     // to 0
#define vturnOff4__init()          { _Set0_( vturnOff4 ); }
#define vturnOff4__to_0()          vturnOff4_TO_0()
#define vturnOff4__to_1()          vturnOff4_TO_1()

void vturn__init(void);
void vturn_34_follow_key1_once(void);

#endif
