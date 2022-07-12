
#include "main.h"

extern uint8_t _key_1_value_t1 ;

void vturn_34_follow_key1_once(void){

    if ( _key_1_value_t1 ) { // 4
        vturn_on_4();
    } else { //                 3
        vturn_on_3();
    }

} // vturn_34_follow_key1_once

void vturn_on_3(void){
    xCharge3_on();
    //xCharge4_off();
    //xHost3_on();
    //xHost4_off();
} // vturn_on_3
void vturn_on_4(void){
    //xCharge4_on();
    xCharge3_off();
    //xHost4_on();
    //xHost3_off();
} // vturn_on_4
