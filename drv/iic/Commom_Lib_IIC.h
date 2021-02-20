#include "all_config.h"
#include "../MyLib/drv/nativeInterface.h"

void IIC_init();
void IIC_write(uint16_t addr, uint16_t reg,  uint16_t length, uint8_t *data_t);
void IIC_read(uint16_t addr, uint16_t reg, uint16_t length, uint8_t *data_t);
