

#include "main.h"

uint8_t ledB = LedBr0 ;
// TA0IV
    __attribute__((interrupt(TIMER0_A0_VECTOR))) // 0x57 0xfff8
void interupt_timer0_a0_isr(void)
{
    _Y1( LED_flash,        led12 );
    TA0CTL &= (~TAIFG);
    TA0CCTL0 &= (~CCIFG) ;
    TA0CCTL1 &= (~CCIFG) ;
    TA0CCTL2 &= (~CCIFG) ;
} // _interupt_timer0_a0_isr

    __attribute__((interrupt(TIMER0_A1_VECTOR))) // 0x56 0xfff6
void interupt_timer0_a1_isr(void)
{
    if ( (TA0CCTL0 & CCIFG) ) {
        _Y1( LED_on,          led12 );
        TA0CCTL0 &= (~CCIFG) ;
    }
    if ( (TA0CCTL1 & CCIFG) ) {
        _Y1( LED_off,        led12 );
        TA0CCTL1 &= (~CCIFG) ;
    }
    TA0CTL &= (~TAIFG);
} // _interupt_timer0_a1_isr
void interupt_init_ccr1_for_led_brightness(void) {
    //TA0CCTL0 =            CCIE ;                      // CCR1 reset/set
    TA0CCTL1 = OUTMOD_7 | CCIE ;                      // CCR1 reset/set
    TA0CCR0 = 320 ;                         // PWM Period , as the count-up maximum, which is use CCR0
    TA0CCR1 =   5;                           // CCR1 PWM duty cycle

    TA0CTL = TASSEL__ACLK | ID__1 | MC__UP | TACLR | TAIE;  // ACLK(32768Hz), up mode, clear TAR
}
