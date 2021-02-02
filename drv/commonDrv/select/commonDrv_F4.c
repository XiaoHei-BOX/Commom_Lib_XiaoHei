#include "commonDrv.h"
#include <stdio.h>

#ifdef STM32_F4

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
     HAL_SYSTICK_CLKSourceConfig(0x00000000U);
	 int fputc(int ch, FILE *f)
	{
		HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
		return ch;
	}
}

void myPrint(const char *str)
{
	
}
#endif