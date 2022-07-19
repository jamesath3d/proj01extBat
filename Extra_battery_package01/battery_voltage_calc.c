
#include "main.h"


// 0    PctVolts_Dischrg=8.0
// 5    PctVolts_Dischrg=10.0
// 10   PctVolts_Dischrg=10.2  --- 0
// 20   PctVolts_Dischrg=10.45 --- 1
//
// 30   PctVolts_Dischrg=10.62 --- 2
// 60   PctVolts_Dischrg=10.98 --- 3
//
// 95   PctVolts_Dischrg=11.96 --- 4
// 100  PctVolts_Dischrg=12.1  
// 0    PctVolts_Chrg=9.5
// 10   PctVolts_Chrg=10.56
// 100  PctVolts_Chrg=12.29

uint8_t _battery_mv_calc_ledLevel( uint32_t ___battery_mv ) {
    static  uint8_t __battery_ledLevel ;
    __battery_ledLevel = 0 ;

    //led_1234_init_test_by_byte
    if ( ___battery_mv <                         9954 ) {   // 10% , 
        __battery_ledLevel                          = 0 ;
    } else {
        if ( ___battery_mv <                    10572 ) {   // 20%, 
            __battery_ledLevel                      = 1 ;
        } else {
            if ( ___battery_mv <                10884 ) {   // 40%, 
                __battery_ledLevel                  = 2 ;
            } else {
                if ( ___battery_mv <            11328 ) {   // 60%, 
                    __battery_ledLevel              = 3 ;
                } else {
                    if ( ___battery_mv <        11754 ) {   // 80%, 
                        __battery_ledLevel          = 4 ;
                    } else {
                        if ( ___battery_mv <    12006 ) {  // 90%, 
                            __battery_ledLevel      = 5 ;     // most-full
                        } else {
                            __battery_ledLevel      = 6 ;     // all-full
                        }
                    }
                }
            }
        }
    }
    return __battery_ledLevel ;

} //    _battery_mv_calc_ledLevel
