
#include "main.h"


/*
   For more safe, we can select the 9.954v as the end-discharge point, 
   then, we can select :
   4007   second, 12.006v    LED1,2,3,4,5, two color   : 
   8008   second, 11.754v    LED1,2,3,4,5, one color   : 
   16005 second, 11.328v    LED1,2,3,4   , one color
   24007 second, 10.884v    LED1,2,3      , one color
   32012 second, 10.572v    LED1,2          , one color
   36015 second, 10.284v    LED1              , one color
   40002 second, 9.954v      LED1              , one color, but 8 second flash eventhough no key being pressed.
Then : 
LED 2+3+5 : below 9.954v : must charge at once
LED 1+2 : between 9.954v and 10.572v 
LED 1+2 : between 10.572v and 10.884 
LED 1+2+3: between 10.884 and 11.328v
LED 1+2+3+4 : between 11.328 and 11.754v
LED 1+2+3+4+5 : higher than 11.754v
Before discharged to 9.954, 40002 second , 11.1 hours passed.
Because the H420 work in a half power status, so, maybe , 5.5 hours is a tatal expected working time.
*/

uint8_t _battery_mv_calc_ledLevel( uint32_t ___battery_mv ) {
    static  uint8_t __battery_ledLevel ;
    __battery_ledLevel = 0 ;

    //led_1234_init_test_by_byte
    if ( ___battery_mv <                            9954 ) {   // 5% , 
        __battery_ledLevel                          = 0 ;
    } else {
        if ( ___battery_mv <                        10284 ) {   // 10%, 
            __battery_ledLevel                      = 1 ;
        } else {
            if ( ___battery_mv <                    10572 ) {   // 20%, 
                __battery_ledLevel                  = 2 ;
            } else {
                if ( ___battery_mv <                10884 ) {   // 40%, 
                    __battery_ledLevel              = 3 ;
                } else {
                    if ( ___battery_mv <            11328 ) {   // 60%, 
                        __battery_ledLevel          = 4 ;
                    } else {
                        if ( ___battery_mv <        11754 ) {   // 80%, 
                            __battery_ledLevel      = 5 ;
                        } else {
                            if ( ___battery_mv <    12006 ) {  // 90%, 
                                __battery_ledLevel  = 6 ;     // most-full
                            } else {
                                __battery_ledLevel  = 7 ;     // all-full
                            }
                        }
                    }
                }
            }
        }
    }
    return __battery_ledLevel ;

} //    _battery_mv_calc_ledLevel
