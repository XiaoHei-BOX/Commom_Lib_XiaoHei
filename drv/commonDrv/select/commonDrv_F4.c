#include "../MyLib/drv/commonDrv/commonDrv.h"
#include <stdio.h>

#ifdef STM32_F4

static int fac_us=0;

void myDelayMS(uint64_t t)
{
    int i;
	for(i=0;i<t;i++) myDelayUS(1000);
}

void myDelayUS(uint64_t t)
{
    int ticks;
	int told,tnow,tcnt=0;
	int reload=SysTick->LOAD;
	ticks=t*fac_us; 						 
	told=SysTick->VAL;        				
	while(1)
	{
		tnow=SysTick->VAL;	
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;	
			else tcnt+=reload-tnow+told;	    
			told=tnow;
			if(tcnt>=ticks)break;			
		}  
	};
}

uint64_t myGetMS()
{
}

void myCommonInit()
{
     HAL_SYSTICK_CLKSourceConfig(0x00000000U);

}

void myPrint(const char *str)
{
	
}
#endif
