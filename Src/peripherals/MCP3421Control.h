//*****************************************************************************
//
//
//
//*****************************************************************************


#ifndef _MCP3421CONTROL_H_
#define _MCP3421CONTROL_H_

#include "stdint.h"
#include "stdbool.h"

uint8_t MCP3421_WriteData(uint8_t I2C_Channel, uint8_t Reg);
uint32_t MCP3421_ReadData(uint8_t I2C_Channel);
uint32_t GetCurrrent(uint8_t I2C_Channel);


#endif


