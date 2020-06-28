//*****************************************************************************
//
// 
//
//*****************************************************************************

#ifndef __MY_IIC_H__
#define __MY_IIC_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "driverlib/sysctl.h"
#include "timercontrol.h"


#define IIC_CHANNEL_SUM    11//iic channels sum total number

typedef struct 
{
	uint32_t PortBase;
	uint32_t PortSDA;
	uint32_t PortSCL;
}
IIC_CONFIG;

void I2CInit(void);
void I2CSetSDAHigh( uint8_t I2C_Channel );
void I2CSetSDALow ( uint8_t I2C_Channel );
void I2CSetSCLHigh( uint8_t I2C_Channel );
void I2CSetSCLLow ( uint8_t I2C_Channel );
void I2CStop(uint8_t I2C_Channel);
void I2CStart(uint8_t I2C_Channel);
bool I2CGetACK(uint8_t I2C_Channel);
void I2CSetACK(uint8_t I2C_Channel);
void I2CSetNACK(uint8_t I2C_Channel);

void    I2C_SendByte(uint8_t I2C_Channel, uint8_t lAddress);
uint8_t I2C_ReadByte(uint8_t I2C_Channel);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif 

