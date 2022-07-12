
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
    if ( ___battery_mv <                    10200 ) {   // 10% , 0000_1
        __battery_ledLevel                         = 0 ;
    } else {
        if ( ___battery_mv <                10450 ) {   // 20%, 0001_1
            __battery_ledLevel                     = 1 ;
        } else {
            if ( ___battery_mv <            10620 ) {   // 30%, 0011_1
                __battery_ledLevel                 = 2 ;
            } else {
                if ( ___battery_mv <        10980 ) {   // 65%, 0110_1
                    __battery_ledLevel             = 3 ;
                } else {
                    if ( ___battery_mv <    11960 ) {   // 95%, 0110_1
                        __battery_ledLevel         = 4 ;
                    } else {
                        __battery_ledLevel         = 5 ;     // full
                    }
                }
            }
        }
    }
    return __battery_ledLevel ;

} //    _battery_mv_calc_ledLevel
