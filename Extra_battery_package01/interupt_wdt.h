
#ifndef _INTERUPT_WDT_H
#define _INTERUPT_WDT_H

#include "main.h"

/* WDT is clocked by VLO (assumed 10KHz) see WDT_ADLY_1000 */
#define WDT_VLO_4200ms    (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO)                /* 4200ms   */
#define WDT_VLO_1050ms    (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO+WDTIS0)         /* 1050ms   */
#define WDT_VLO_60ms      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO+WDTIS1)         /* 60ms     */
#define WDT_VLO_7ms1      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL__VLO+WDTIS1+WDTIS0)  /* 7.1ms    */

void wdt_test(void) ;

#endif
