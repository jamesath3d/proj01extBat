
#ifndef led__init_h
#define led__init_h

/*
// p1.6/red
#define _LED_red_PORT_            1
#define _LED_red_PIN_             6
#define _LED_red_TO_1()           { _Set1_(_LED_red); }     // to 1
#define _LED_red_TO_0()           { _Set0_(_LED_red); }     // to 0
#define _LED_red_set_out()        { _SetOUT_( _LED_red ); }
#define _LED_red_on()             _LED_red_TO_0()
#define _LED_red_off()            _LED_red_TO_1()
*/

// p1.6/led_11
#define led_11_PORT_            1
#define led_11_PIN_             6
#define led_11_TO_1()           { _Set1_(led_11); }     // to 1
#define led_11_TO_0()           { _Set0_(led_11); }     // to 0
#define led_11_set_out()        { _SetOUT_( led_11 ); }
#define led_11_on()             led_11_TO_0()
#define led_11_off()            led_11_TO_1()

// p1.7/led_12
#define led_12_PORT_            1
#define led_12_PIN_             7
#define led_12_TO_1()           { _Set1_(led_12); }     // to 1
#define led_12_TO_0()           { _Set0_(led_12); }     // to 0
#define led_12_set_out()        { _SetOUT_( led_12 ); }
#define led_12_on()             led_12_TO_0()
#define led_12_off()            led_12_TO_1()

// p3.2/led_13
#define led_13_PORT_            3
#define led_13_PIN_             2
#define led_13_TO_1()           { _Set1_(led_11); }     // to 1
#define led_13_TO_0()           { _Set0_(led_11); }     // to 0
#define led_13_set_out()        { _SetOUT_( led_11 ); }
#define led_13_on()             led_13_TO_0()
#define led_13_off()            led_13_TO_1()

// p2.7/led_14
#define led_14_PORT_            2
#define led_14_PIN_             7
#define led_14_TO_1()           { _Set1_(led_11); }     // to 1
#define led_14_TO_0()           { _Set0_(led_11); }     // to 0
#define led_14_set_out()        { _SetOUT_( led_11 ); }
#define led_14_on()             led_14_TO_0()
#define led_14_off()            led_14_TO_1()


void led_1234_init(void);
void led_1234_init_test_loop(void);

#endif
