
#ifndef _VTURN__INIT_H
#define _VTURN__INIT_H


#define vturnOff_42_PORT_           2
#define vturnOff_42_PIN_            7
#define vturnOff_41_PORT_           2
#define vturnOff_41_PIN_            5

#define vturnOff_32_PORT_           2
#define vturnOff_32_PIN_            0
#define vturnOff_31_PORT_           3
#define vturnOff_31_PIN_            2

#define pMosG4__PORT_               2
#define pMosG4__PIN_                2
#define pMosG3__PORT_               3
#define pMosG3__PIN_                0


//#define vturnOff3_TO_1()           {             _SetIN_(vturnOff3y);              _SetIN_(vturnOff4); }     // to 1
//#define vturnOff3_TO_0()           {            _SetOUT_(vturnOff3y);             _SetOUT_(vturnOff4); }     // to 0
//#define vturnOff3__init()          { _PinInAsOffInitOut0(vturnOff3y);  _PinInAsOffInitOut0(vturnOff4); }
//
//#define vturnOff4_TO_1()           {              _SetIN_(vturnOff4y);             _SetIN_(vturnOff3); }     // to 1
//#define vturnOff4_TO_0()           {             _SetOUT_(vturnOff4y);            _SetOUT_(vturnOff3); }     // to 0
//#define vturnOff4__init()          {  _PinInAsOffInitOut0(vturnOff4y); _PinInAsOffInitOut0(vturnOff3); }

#define vturnOff3__to_0()          {}
#define vturnOff3__to_1()          {}
#define vturnOff3__init()          {}

#define vturnOff4__to_0()          {}
#define vturnOff4__to_1()          {}
#define vturnOff4__init()          {}

void vturn__init(void);
void vturn_34_follow_key1_once(void);

#endif
