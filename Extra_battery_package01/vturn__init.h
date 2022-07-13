
#ifndef _VTURN__INIT_H
#define _VTURN__INIT_H


#define vLedBlue        2,5
#define vLedGreen       2,2
#define vturn3_acset    2,0
#define vturn3_ovpset   2,1

//#define pMosGall pMosG3,pMosG4
//#define vturn3_acset VturnOff32
//#define vTurn4 VturnOff42
//#define pMosGall pMosG3,pMosG4,VturnOff42

//        _Y1( LED_on,    led11 );
//        _Y1( LED_off,   led11 );

#define vturnOff3ip__to_0()             {   _Y1( _Set0X,        vturn3_acset  ); }
#define vturnOff3ip__to_1()             {   _Y1( _Set1X,        vturn3_acset  ); }
#define xCharge3_on                     vturnOff3ip__to_0
#define xCharge3_off                    vturnOff3ip__to_1

#define vturnOff3ip_acset__init()       {   _Y1( _SetOutX0,     vturn3_acset  ); }
#define vturnOff3vp_ovpset_init()       {   _Y1( _SetOutX0,     vturn3_ovpset  ); }
#define pMosLedBlue__init()             {   _Y1( _SetOutX0,     vLedBlue  ); }
#define pMosLedGreen__init()            {   _Y1( _SetOutX1,     vLedGreen  ); }


#define xLedBlue_off()                  {   _Y1( _Set1X,        vLedBlue  ); }
#define xLedGreen_off()                 {   _Y1( _Set1X,        vLedGreen  ); }
#define xLedBlue_on()                   {   _Y1( _Set0X,        vLedBlue  ); }
#define xLedGreen_on()                  {   _Y1( _Set0X,        vLedGreen  ); }

#define xLedBlueGreenOff()              {   xLedBlue_off();     xLedGreen_off(); }
#define xLedBlueGreenOn()               {   xLedBlue_on();      xLedGreen_on(); }
#define xLedBlueOn()                    {   xLedBlue_on();      xLedGreen_off(); }
#define xLedGreenOn()                   {   xLedBlue_off();     xLedGreen_on(); }

//#define vturnOff4__init()

void vturn__init(void);
void vturn_34_follow_key1_once(void);
void vturn_on_4(void);
void vturn_on_3(void);
void vturn_off_4(void);
void vturn_off_3(void);


#endif
