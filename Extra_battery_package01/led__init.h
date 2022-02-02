
#ifndef _LED__INIT_H
#define _LED__INIT_H

// p1.6/led_11
#define led_11_PORT_            1
#define led_11_PIN_             6
// p1.7/led_12
#define led_12_PORT_            1
#define led_12_PIN_             7
// p3.2/led_13
#define led_13_PORT_            3
#define led_13_PIN_             2
// p2.7/led_14
#define led_14_PORT_            2
#define led_14_PIN_             7

#define LED_USE_INPUT1_OUTPUT0
#ifdef LED_USE_INPUT1_OUTPUT0 // off -> input(hi-Z), on -> output_0

#define led_11_TO_0()           { _SetOUT_(led_11); }     // to 0
#define led_12_TO_0()           { _SetOUT_(led_12); }     // to 0
#define led_13_TO_0()           { _SetOUT_(led_13); }     // to 0
#define led_14_TO_0()           { _SetOUT_(led_14); }     // to 0
#define led_11_init()           { _PinInAsOffInitOut0(led_11); }
#define led_12_init()           { _PinInAsOffInitOut0(led_12); }
#define led_13_init()           { _PinInAsOffInitOut0(led_13); }
#define led_14_init()           { _PinInAsOffInitOut0(led_14); }
#define led_11_TO_1()           { _SetIN_(led_11); }     // to 1
#define led_12_TO_1()           { _SetIN_(led_12); }     // to 1
#define led_13_TO_1()           { _SetIN_(led_13); }     // to 1
#define led_14_TO_1()           { _SetIN_(led_14); }     // to 1

#else // off -> 1 , on -> 0 // output

#define led_11_TO_0()           { _Set0_( led_11 ); }     // to 0
#define led_12_TO_0()           { _Set0_( led_12 ); }     // to 0
#define led_13_TO_0()           { _Set0_( led_13 ); }     // to 0
#define led_14_TO_0()           { _Set0_( led_14 ); }     // to 0
#define led_11_init()           { _SetOUT_(led_11); }     // }
#define led_12_init()           { _SetOUT_(led_12); }     // }
#define led_13_init()           { _SetOUT_(led_13); }     // }
#define led_14_init()           { _SetOUT_(led_14); }     // }
#define led_11_TO_1()           { _Set1_( led_11 ); }     // to 1
#define led_12_TO_1()           { _Set1_( led_12 ); }     // to 1
#define led_13_TO_1()           { _Set1_( led_13 ); }     // to 1
#define led_14_TO_1()           { _Set1_( led_14 ); }     // to 1

#endif

#define led_11_on()             led_11_TO_0()
#define led_12_on()             led_12_TO_0()
#define led_13_on()             led_13_TO_0()
#define led_14_on()             led_14_TO_0()

#define led_11_off()            led_11_TO_1()
#define led_12_off()            led_12_TO_1()
#define led_13_off()            led_13_TO_1()
#define led_14_off()            led_14_TO_1()

#define led_11_read()           _READbit_(led_11)
#define led_12_read()           _READbit_(led_12)
#define led_13_read()           _READbit_(led_13)
#define led_14_read()           _READbit_(led_14)


void led_1234_init_all_off(void);
void led_1234_init_test_loop(void);
void led_1_blink_once(void);
void led_1234_init_test_once(void);
void led_2_blink_once(void);
void led_12_follow_dcdc_status34(void);

#endif
