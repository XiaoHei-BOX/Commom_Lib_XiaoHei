#include "../MyLib/drv/commonDrv/commonDrv.h"

#ifdef service_input_keypad

#ifndef __Keypad_H__
#define __Keypad_H__

void initKeypad(void (*callback)(unsigned char x, unsigned char y));

void scanKeypad();

#endif
#endif
