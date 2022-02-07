
#ifndef _VTURN__INIT_H
#define _VTURN__INIT_H


// p2.3/vturnOff3 
#define vturnOff3_PORT_            2
#define vturnOff3_PIN_             3
// p3.1/vturnOff3x // J551-1,
#define vturnOff3x_PORT_           3
#define vturnOff3x_PIN_            1
// p2.5/vturnOff3y // J561-1,
#define vturnOff3y_PORT_           2
#define vturnOff3y_PIN_            5

#define vturnOff3_TO_1()           {             _SetIN_(vturnOff3y);              _SetIN_(vturnOff4); }     // to 1
#define vturnOff3_TO_0()           {            _SetOUT_(vturnOff3y);             _SetOUT_(vturnOff4); }     // to 0
#define vturnOff3__init()          { _PinInAsOffInitOut0(vturnOff3y);  _PinInAsOffInitOut0(vturnOff4); }

#define vturnOff3__to_0()          vturnOff3_TO_0()
#define vturnOff3__to_1()          vturnOff3_TO_1()

// p2.2/vturnOff4
#define vturnOff4_PORT_            2
#define vturnOff4_PIN_             2
// p2.4/vturnOff4x // J551-2
#define vturnOff4x_PORT_           2
#define vturnOff4x_PIN_            4
// p2.6/vturnOff4y // J561-2
#define vturnOff4y_PORT_           2
#define vturnOff4y_PIN_            6

/*
#define vturnOff4_TO_1()           {  _SetIN_(vturnOff4);  _SetIN_(vturnOff4x);  _SetIN_(vturnOff4y); }     // to 1
#define vturnOff4_TO_0()           { _SetOUT_(vturnOff4); _SetOUT_(vturnOff4x); _SetOUT_(vturnOff4y); }     // to 0
#define vturnOff4__init()          {   _Set0_(vturnOff4);   _Set0_(vturnOff4x);   _Set0_(vturnOff4y); }
*/
#define vturnOff4_TO_1()           {              _SetIN_(vturnOff4y);             _SetIN_(vturnOff3); }     // to 1
#define vturnOff4_TO_0()           {             _SetOUT_(vturnOff4y);            _SetOUT_(vturnOff3); }     // to 0
#define vturnOff4__init()          {  _PinInAsOffInitOut0(vturnOff4y); _PinInAsOffInitOut0(vturnOff3); }
#define vturnOff4__to_0()          vturnOff4_TO_0()
#define vturnOff4__to_1()          vturnOff4_TO_1()

void vturn__init(void);
void vturn_34_follow_key1_once(void);

#endif
