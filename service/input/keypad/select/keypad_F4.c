#include "keypad.h"
#include "keypad_drv.h"


#ifdef service_input_keypad
#ifdef STM32_F4

#define row1_gpio GPIOF
#define row1_pin GPIO_PIN_1
#define row2_gpio GPIOF
#define row2_pin GPIO_PIN_2
#define row3_gpio GPIOF
#define row3_pin GPIO_PIN_3
#define row4_gpio GPIOF
#define row4_pin GPIO_PIN_4

#define col1_gpio GPIOF
#define col1_pin GPIO_PIN_5
#define col2_gpio GPIOF
#define col2_pin GPIO_PIN_6
#define col3_gpio GPIOF
#define col3_pin GPIO_PIN_7
#define col4_gpio GPIOF
#define col4_pin GPIO_PIN_8


void initInput()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (PULL=0)
    {
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    }
    else
    {
        GPIO_InitStruct.Pull = GPIO_PULLUP;
    }
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;

    GPIO_InitStruct.Pin = row1_pin;
    HAL_GPIO_Init(row1_gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = row2_pin;
    HAL_GPIO_Init(row2_gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = row3_pin;
    HAL_GPIO_Init(row3_gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = row4_pin;
    HAL_GPIO_Init(row4_gpio, &GPIO_InitStruct);

}
void initOutput()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (PULL=0)
    {
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    }
    else
    {
        GPIO_InitStruct.Pull = GPIO_PULLUP;
    }

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;

    GPIO_InitStruct.Pin = col1_pin;
    HAL_GPIO_Init(col1_gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = col2_pin;
    HAL_GPIO_Init(col2_gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = col3_pin;
    HAL_GPIO_Init(col3_gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = col4_pin;
    HAL_GPIO_Init(col4_gpio, &GPIO_InitStruct);

}
void setOutput(unsigned int index)
{
    switch (index)
    {
    case 1:
        HAL_GPIO_WritePin(col1_gpio,col1_pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(col2_gpio,col2_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col3_gpio,col3_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col4_gpio,col4_pin,GPIO_PIN_RESET);
        break;
    case 2:
        HAL_GPIO_WritePin(col1_gpio,col1_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col2_gpio,col2_pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(col3_gpio,col3_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col4_gpio,col4_pin,GPIO_PIN_RESET);
        break;
    case 3:
        HAL_GPIO_WritePin(col1_gpio,col1_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col2_gpio,col2_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col3_gpio,col3_pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(col4_gpio,col4_pin,GPIO_PIN_RESET);
        break;
    case 4:
        HAL_GPIO_WritePin(col1_gpio,col1_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col2_gpio,col2_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col3_gpio,col3_pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(col4_gpio,col4_pin,GPIO_PIN_SET);
        break;
    }
    

}
int readInput()
{
    int row;
    if (HAL_GPIO_ReadPin(col1_gpio,col1_pin)==1)
    {
        return 1;
    }
    if (HAL_GPIO_ReadPin(col2_gpio,col2_pin)==1)
    {
        return 2;
    }
    if (HAL_GPIO_ReadPin(col2_gpio,col2_pin)==1)
    {
        return 3;
    }
    if (HAL_GPIO_ReadPin(col2_gpio,col2_pin)==1)
    {
        return 4;
    }

}


#endif 
#endif