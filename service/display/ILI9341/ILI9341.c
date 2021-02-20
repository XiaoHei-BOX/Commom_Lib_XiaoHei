#include "ILI9341.h"
#include "ILI9341_Drv.h"

#ifdef service_display_ILI9341

//LCD的画笔颜色和背景色	   
uint16_t POINT_COLOR=0x0000;	//画笔颜色
uint16_t BACK_COLOR=0xFFFF;  //背景色
 
//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;


void LCD_WR_REG(uint16_t regval)
{		
	LCD->LCD_REG=regval;	
}
void LCD_WR_DATA(uint16_t data)
{
    LCD->LCD_RAM=data;
}
uint16_t LCD_RD_DATA(void)
{
    vu16 ram;			
	ram=LCD->LCD_RAM;	
	return ram;	
}
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue)
{
    LCD->LCD_REG = LCD_Reg;			 
	LCD->LCD_RAM = LCD_RegValue;
}
uint16_t LCD_ReadReg(uint16_t LCD_Reg)
{
    LCD_WR_REG(LCD_Reg);		
	myDelayUS(5);		  
	return LCD_RD_DATA();	
}
void LCD_WriteRAM_Prepare(void)
{
 	LCD->LCD_REG=lcddev.wramcmd;	  
}	 
void LCD_WriteRAM(vu16 RGB_Code)
{							    
	LCD->LCD_RAM = RGB_Code;
}

void LCD_Clear(u32 color)
{
    u32 index=0;
	u32 totalpoint=lcddev.width;
	totalpoint*=lcddev.height; 			//得到总点数

	//LCD_SetCursor(0x00,0x0000);			//设置光标位置

	LCD_WR_REG(lcddev.setxcmd); 
	LCD_WR_DATA(0x00>>8);LCD_WR_DATA(0x00&0XFF);
	LCD_WR_REG(lcddev.setycmd); 
	LCD_WR_DATA(0x0000>>8);LCD_WR_DATA(0x0000&0XFF);
	LCD_WriteRAM_Prepare();     		//开始写入GRAM			

	for(index=0;index<totalpoint;index++)
	{
		LCD->LCD_RAM=color;	
	} 

}





void LCD_Init(void)
{
        LCD_WR_REG(0xCF);  
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0xC1); 
		LCD_WR_DATA(0X30); 
		//功耗控制B
		LCD_WR_REG(0xED);  
		LCD_WR_DATA(0x64); 
		LCD_WR_DATA(0x03); 
		LCD_WR_DATA(0X12); 
		LCD_WR_DATA(0X81); 
		//电源时序控制A
		LCD_WR_REG(0xE8);  
		LCD_WR_DATA(0x85); 
		LCD_WR_DATA(0x10); 
		LCD_WR_DATA(0x7A); 
		//驱动时序控制A
		LCD_WR_REG(0xCB);  
		LCD_WR_DATA(0x39); 
		LCD_WR_DATA(0x2C); 
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0x34); 
		LCD_WR_DATA(0x02);
		//功耗控制A
		LCD_WR_REG(0xF7);  
		LCD_WR_DATA(0x20);
		//泵比控制
		LCD_WR_REG(0xEA);  
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0x00); 
		//驱动时序控制B
		LCD_WR_REG(0xC0);
		LCD_WR_DATA(0x1B);
		//功耗控制1
		LCD_WR_REG(0xC1);
		LCD_WR_DATA(0x01);
		//功耗控制2
		LCD_WR_REG(0xC5);
		LCD_WR_DATA(0x30);
		LCD_WR_DATA(0x30);
		//VCOM控制1
		LCD_WR_REG(0xC7);
		LCD_WR_DATA(0XB7); 
		//VCOM控制2
		LCD_WR_REG(0x36);
		LCD_WR_DATA(0x48); 
		//存储器访问控制
		LCD_WR_REG(0x3A);   
		LCD_WR_DATA(0x55); 
		LCD_WR_REG(0xB1);   
		LCD_WR_DATA(0x00);   
		LCD_WR_DATA(0x1A); 
		//像素格式设置
		LCD_WR_REG(0xB6);
		LCD_WR_DATA(0x0A); 
		LCD_WR_DATA(0xA2);
		//显示功能设置控制
		LCD_WR_REG(0xF2);
		LCD_WR_DATA(0x00);
		//使能3G
		LCD_WR_REG(0x26);
		LCD_WR_DATA(0x01); 
		//伽马设置
		LCD_WR_REG(0xE0);
		LCD_WR_DATA(0x0F); 
		LCD_WR_DATA(0x2A); 
		LCD_WR_DATA(0x28); 
		LCD_WR_DATA(0x08); 
		LCD_WR_DATA(0x0E); 
		LCD_WR_DATA(0x08); 
		LCD_WR_DATA(0x54); 
		LCD_WR_DATA(0XA9); 
		LCD_WR_DATA(0x43); 
		LCD_WR_DATA(0x0A); 
		LCD_WR_DATA(0x0F); 
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0x00);
		//正极伽马校正
		LCD_WR_REG(0XE1);    //Set Gamma 
		LCD_WR_DATA(0x00); 
		LCD_WR_DATA(0x15); 
		LCD_WR_DATA(0x17); 
		LCD_WR_DATA(0x07); 
		LCD_WR_DATA(0x11); 
		LCD_WR_DATA(0x06); 
		LCD_WR_DATA(0x2B); 
		LCD_WR_DATA(0x56); 
		LCD_WR_DATA(0x3C); 
		LCD_WR_DATA(0x05); 
		LCD_WR_DATA(0x10); 
		LCD_WR_DATA(0x0F); 
		LCD_WR_DATA(0x3F); 
		LCD_WR_DATA(0x3F); 
		LCD_WR_DATA(0x0F); 
		//负极伽马校正
		LCD_WR_REG(0x2B); 
		LCD_WR_DATA(0x00);
		LCD_WR_DATA(0x00);
		LCD_WR_DATA(0x01);
		LCD_WR_DATA(0x3f);
		//行地址设置
		LCD_WR_REG(0x2A); 
		LCD_WR_DATA(0x00);
		LCD_WR_DATA(0x00);
		LCD_WR_DATA(0x00);
		LCD_WR_DATA(0xef);	 
		//列地址设置
		LCD_WR_REG(0x11);
		myDelayMS(120);
		LCD_WR_REG(0x29);
		//退出睡眠模式
//////////////////////////——屏幕显示方式——//////////////////////////////////////
        lcddev.dir=0;	     //竖屏
		lcddev.width=240;
		lcddev.height=320;
		lcddev.wramcmd=0X2C;
	 	lcddev.setxcmd=0X2A;
		lcddev.setycmd=0X2B;

        LCD_WriteReg(0x36,0|(0<<7)|(0<<6)|(0<<5)|0x08);
        LCD_WR_REG(lcddev.setxcmd); 
		LCD_WR_DATA(0);
		LCD_WR_DATA(0);
		LCD_WR_DATA((lcddev.width-1)>>8);
		LCD_WR_DATA((lcddev.width-1)&0XFF);
		
		LCD_WR_REG(lcddev.setycmd); 
		LCD_WR_DATA(0);
		LCD_WR_DATA(0);
		LCD_WR_DATA((lcddev.height-1)>>8);
		LCD_WR_DATA((lcddev.height-1)&0XFF);  
////////////////////////////////////////////////////////////////////////////////
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);//点亮背光

        LCD_Clear(0x001F);

}







#endif
