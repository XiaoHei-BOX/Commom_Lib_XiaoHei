#include "Commom_Lib_IIC.h"
#include <stdio.h>

#ifdef STM32_F4

    extern I2C_HandleTypeDef hi2c1;
void IIC_init();
{
    
}
void IIC_write(uint16_t addr, uint16_t reg,  uint16_t length, uint8_t *data_t);
{
    HAL_I2C_Mem_Write(&hi2c1,addr,reg,I2C_MEMADD_SIZE_8BIT,data_t,length,100);
}
void IIC_read(uint16_t addr, uint16_t reg, uint16_t length, uint8_t *data_t);
{
    HAL_I2C_Mem_Read(&hi2c1,addr,reg,I2C_MEMADD_SIZE_8BIT,data_t,length,100);
}

#endif