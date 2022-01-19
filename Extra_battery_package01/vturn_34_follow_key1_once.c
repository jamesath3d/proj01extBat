
#include "main.h"

extern uint8_t _key_1_value_t1 ;

} // led_34_follow_key1_onceX

void vturn_34_follow_key1_once(void){

        if ( _key_1_value_t1 ) {
            vturn3_to_0();
            vturn4_to_1();
        } else {
            vturn3_to_1();
            vturn4_to_0();
        }
    }

} // vturn_34_follow_key1_once

