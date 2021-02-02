#include "drv/nativeInterface.h"

#ifdef service_input_keypad

	#define PULL 1 //1=UP 0=DOWN
	void initInput();
	void initOutput();
	void setOutput(unsigned int index);
	int readInput();


#endif