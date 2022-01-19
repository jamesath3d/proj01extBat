
#include "main.h"

extern uint8_t _key_1_value_t1 ;

void vturn_34_follow_key1_once(void){

    if ( _key_1_value_t1 ) {
        vturnOff3__to_0();
        vturnOff4__to_1();
    } else {
        vturnOff3__to_1();
        vturnOff4__to_0();
    }

} // vturn_34_follow_key1_once

