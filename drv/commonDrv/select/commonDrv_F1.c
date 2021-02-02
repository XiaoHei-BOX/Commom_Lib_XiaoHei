#include "commonDrv.h"
#ifdef STM32_F1

static u32 fac_us=0;

void myDelayMS(uint64_t t)
{
   	u32 i;
	for(i=0;i<t;i++) myDelayUS(1000);
}

void myDelayUS(uint64_t t)
{
    u32 ticks;
	u32 told,tnow,tcnt=0;
	u32 reload=SysTick->LOAD;					    	 
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
    HAL_SYSTICK_CLKSourceConfig(0x00000004U);
}

void myPrint(const char *str)
{
}
#endif