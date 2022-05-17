

#include "main.h"

// TA0IV
    __attribute__((interrupt(TIMER0_A0_VECTOR))) // 0x57 0xfff8
void _interupt_timer0_a0_isr(void)
{
    /*
       switch(__even_in_range(TA0IV,TA0IV_TAIFG))
       {
       case TA0IV_NONE:
       break;                             // No interrupt
       case TA0IV_TACCR1:
       _Y1( LED_off,       led11 );
       break;                             // CCR1 not used
       case TA0IV_TACCR2:
       _Y1( LED_off,       led12 );
       break;                             // CCR2 not used
       case TA0IV_TAIFG:                      // overflow
       _Y1( LED_on,        led11 );
       _Y1( LED_on,        led12 );
       break;
       default:
       break;
       }
       */
    //_Y1( LED_on,         led11 );
    _Y1( LED_flash,        led12 );
    TA0CTL &= (~TAIFG);
    TA0CCTL0 &= (~CCIFG) ;
    TA0CCTL1 &= (~CCIFG) ;
    TA0CCTL2 &= (~CCIFG) ;
} // _interupt_timer0_a0_isr

    __attribute__((interrupt(TIMER0_A1_VECTOR))) // 0x56 0xfff6
void _interupt_timer0_a1_isr(void)
{
    //_Y1( LED_on,        led13 );
    //P1DIR ^= BIT1 ;
    //_Y1( LED_flash,        led13 );

    uint8_t __tt ;
    __tt = 0 ;

    if ( (TA0CCTL0 & CCIFG) ) {
        _Y1( LED_on,          led12 );
        _Y1( LED_on,          led13 );
        TA0CCTL0 &= (~CCIFG) ;
        __tt |= 1 ;
    }
    if ( (TA0CCTL1 & CCIFG) ) {
        _Y1( LED_off,        led12 );
        TA0CCTL1 &= (~CCIFG) ;
        __tt |= 2 ;
    }
    if ( (TA0CCTL2 & CCIFG) ) {
        _Y1( LED_off,        led13 );
        TA0CCTL2 &= (~CCIFG) ;
        __tt |= 4 ;
    }
    TA0CTL &= (~TAIFG);
} // _interupt_timer0_a1_isr
