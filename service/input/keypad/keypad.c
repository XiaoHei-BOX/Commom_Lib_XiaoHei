#include "keypad.h"
#include "keypad_drv.h"

#ifdef service_input_keypad

static int KeyValue=0;

void initKeypad(void (*callback)(unsigned char x, unsigned char y))
{
    
}
void scanKeypad()
{
    setOutput(1);
    if (readInput()!=0)
    {
        switch (readInput())
        {
            case 1:
            KeyValue=1;
                break;
            case 2:
            KeyValue=2;
                break;
            case 3:
            KeyValue=3;
                break;
            case 4:
            KeyValue=4;
                break;
        }
    }
    setOutput(2);
    if (readInput()!=0)
    {
        switch (readInput())
        {
            case 1:
            KeyValue=5;
                break;
            case 2:
            KeyValue=6;
                break;
            case 3:
            KeyValue=7;
                break;
            case 4:
            KeyValue=8;
                break;
        }
    }
    setOutput(3);
    if (readInput()!=0)
    {
        switch (readInput())
        {
            case 1:
            KeyValue=9;
                break;
            case 2:
            KeyValue=10;
                break;
            case 3:
            KeyValue=11;
                break;
            case 4:
            KeyValue=12;


                break;
        }
    }
    setOutput(4);
    if (readInput()!=0)
    {
        switch (readInput())
        {
            case 1:
            KeyValue=13;
                break;
            case 2:
            KeyValue=14;
                break;
            case 3:
            KeyValue=15;
                break;
            case 4:
            KeyValue=16;
                break;
        }
    }
    
}



#endif