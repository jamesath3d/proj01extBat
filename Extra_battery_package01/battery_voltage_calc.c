
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

static  uint8_t battery_led ;
uint8_t battery_mv_calc_led( uint32_t ___battery_mv ) {
    battery_led = 0 ;

    //led_1234_init_test_by_byte
    if ( ___battery_mv <                    10200 ) {   // 10% , 0000_1
        battery_led                     = 0b01101 ;
    } else {
        if ( ___battery_mv <                10450 ) {   // 20%, 0001_1
            battery_led                 = 0b10001 ;
        } else {
            if ( ___battery_mv <            10620 ) {   // 30%, 0011_1
                battery_led             = 0b11001 ;
            } else {
                if ( ___battery_mv <        10980 ) {   // 65%, 0110_1
                    battery_led         = 0b11101 ;
                } else {
                    battery_led             = 0b11111 ;     // 1111_1
                }
            }
        }
    }
    return battery_led ;

} //    battery_mv_calc_led
