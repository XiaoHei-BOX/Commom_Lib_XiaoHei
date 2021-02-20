#include "../MyLib/drv/commonDrv/commonDrv.h"
#include <stdint.h>

#ifdef service_display_ILI9341

#ifndef __ILI9341_H__
#define __ILI9341_H__

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;
typedef __OM  uint8_t    u8;
typedef __OM  uint16_t   u16;
typedef __OM  uint32_t   u32;


#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色




SRAM_HandleTypeDef TFTSRAM_Handler;


typedef struct  
{										    
	uint16_t width;			//LCD 宽度
	uint16_t height;			//LCD 高度
	uint16_t id;				//LCD ID
	uint8_t  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。	
	uint16_t	wramcmd;		//开始写gram指令
	uint16_t  setxcmd;		//设置x坐标指令
	uint16_t  setycmd;		//设置y坐标指令 
}_lcd_dev; 	  

extern _lcd_dev lcddev;	//管理LCD重要参数
//LCD的画笔颜色和背景色	   
extern uint16_t  POINT_COLOR;//默认红色    
extern uint16_t  BACK_COLOR; //背景颜色.默认为白色

typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;

#define LCD_BASE        ((vu32)(0x6C000000 | 0x0000007E))  // 地址是FSMC_A6
//#define LCD_BASE        ((u32)(0x6C000000 | 0x000007FE)) // 地址是FSMC_A10
#define LCD             ((LCD_TypeDef *) LCD_BASE)


void LCD_WR_REG(uint16_t regval);                            //写寄存器值函数
void LCD_WR_DATA(uint16_t data);                             //写数据函数
uint16_t LCD_RD_DATA(void);                                  //读数据函数
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue);   //写寄存器内容函数
uint16_t LCD_ReadReg(uint16_t LCD_Reg);                      //读寄存器内容函数
void LCD_WriteRAM_Prepare(void);                             //开始写GRAM函数
void LCD_WriteRAM(uint16_t RGB_Code);                        //写GRAM函数
void LCD_Clear(vu32 color);
void LCD_Init(void);






#endif
#endif
