#include "commonDrv.h"

#ifdef service_input_keypad

void initKeypad(void (*callback)(unsigned char x, unsigned char y));
void scanKeypad();

#ifdef service_input_keypad