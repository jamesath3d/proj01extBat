

#include "main.h"

volatile uint8_t ledB = LedBr0 ;
const uint8_t ledBarr[] = { LedBrX , LedBr1, LedBr2, LedBr3, LedBr4, LedBr5 , LedBrY };
// TA0IV
    __attribute__((interrupt(TIMER0_A0_VECTOR))) // 0x57 0xfff8
void interupt_timer0_a0_isr(void)
{
    //_Y1( LED_flash,        led12 );
    TA0CTL &= (~TAIFG);
    TA0CCTL0 &= (~CCIFG) ;
    TA0CCTL1 &= (~CCIFG) ;
    TA0CCTL2 &= (~CCIFG) ;
} // _interupt_timer0_a0_isr

    __attribute__((interrupt(TIMER0_A1_VECTOR))) // 0x56 0xfff6
void interupt_timer0_a1_isr(void)
{
    if ( (TA0CCTL0 & CCIFG) ) {
        //_Y1( LED_flash,          led13 );
        //#define _SetInX(p1,b1)              { P ## p1 ## DIR    &= ( ~ BIT ## b1 ) ; }
        //#define _SetOutX(p1,b1)             { P ## p1 ## DIR    |=     BIT ## b1   ; }
        //P1DIR &= ( ~ LedBrMask ) ;
        P1DIR &= LedBrMask ;    // all as input --> off
        P1DIR |= ( ledB & (~LedBrMask) ) ;         // selected as output
        //_Y1( LED_off,        led11 );
        TA0CCTL0 &= (~CCIFG) ;
    }
    if ( (TA0CCTL1 & CCIFG) ) {
        //_Y1( LED_on,        led11 );
        //P1DIR &= ( ~ ledB ) ;
        //P1DIR |= (   LedBr0 ) ;
        //P1DIR &= LedBrMask ;
        P1DIR &= LedBrMask ;    // all as input --> off
        TA0CCTL1 &= (~CCIFG) ;
    }
    TA0CTL &= (~TAIFG);
} // _interupt_timer0_a1_isr
void interupt_init_ccr1_for_led_brightness(void) {
    TA0CCR0 = 500 ;                         // PWM Period , as the count-up maximum, which is use CCR0

    TA0CCTL1 = OUTMOD_7 | CCIE ;             // CCR1 7 PWM reset/set
    //TA0CCR1 =   5;                           // CCR1 PWM duty cycle
    TA0CCR1 =   35;                           // CCR1 PWM duty cycle
    //TA0CCR1 =   95;                           // CCR1 PWM duty cycle
    //TA0CCR1 =  335;                           // CCR1 PWM duty cycle
    //TA0CCTL2 = OUTMOD_7 | CCIE ;           // CCR2 3 PWM set/reset 
    //TA0CCR2 = 115;                         // CCR2 PWM duty cycle

    TA0CTL = TASSEL__ACLK | ID__1 | MC__UP | TACLR | TAIE;  // ACLK(32768Hz), up mode, clear TAR
    //TA0CTL = TASSEL__ACLK | ID__1 | MC__UP | TACLR       ;  // ACLK(32768Hz), up mode, clear TAR
} // interupt_init_ccr1_for_led_brightness
void interupt_init_ccr1_for_led_off(void) {
    //TA0CTL &= ( ~ TAIE ) ;  
    TA0CTL &= ( ~ MC__UPDOWN ) ;
    //ledB = LedBr0 ;
    P1DIR &= LedBrMask ;    // all as input --> off
} // interupt_init_ccr1_for_led_off
void interupt_init_ccr1_for_led_on(void) {
    //TA0CTL |=     TAIE   ;  
    TA0CTL |= MC__UP ;
} // interupt_init_ccr1_for_led_on
