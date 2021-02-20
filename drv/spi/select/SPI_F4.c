#include "../Commom_Lib_SPI.h"
#include <stdio.h>

#ifdef STM32_F4
//extern SPI_HandleTypeDef hspi1;
 
void SPIInit()
{

}
void SPI_write( uint8_t *pData,uint16_t Size)
{
    //HAL_SPI_Transmit(&hspi1, pdata, Size, 100);
}
void SPI_read(uint8_t *pData,uint16_t Size)
{
    //HAL_SPI_Receive(&hspi1, pdata, Size, 100);
}

#endif
