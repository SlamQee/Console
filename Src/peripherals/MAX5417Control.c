/*
 * MA5417.c
 *
 *  Created on: 2017Äê4ÔÂ12ÈÕ
 *      Author: lenovo
 */
#include "MAX5417Control.h"
#include "stdint.h"
#include "stdbool.h"
#include "driverlib/rom.h"
#include "inc/hw_memmap.h"
#include "my_iic.h"
#include "utils/uartstdio.h"
#include "debug.h"


bool MAX5417_WriteData(uint8_t I2C_Channel, uint8_t lAddress, uint8_t lRegister, uint8_t lData)
{
	bool lRt = true;
	uint32_t nTemp;
    
	I2CStart(I2C_Channel);
	
	I2C_SendByte(I2C_Channel, lAddress);
	nTemp = I2CGetACK(I2C_Channel);
	if (!nTemp)
	{
		  lRt =  false;       // slave no ack
		  return lRt;
	}
	
	SysCtlDelay(SYS_DELAY_1US*30);//wait for writting next byte
	
	I2C_SendByte(I2C_Channel, lRegister);
	nTemp = I2CGetACK(I2C_Channel);
	if (!nTemp)
	{
		  lRt =  false;      // slave no ack
		  return lRt;
	}
	
	SysCtlDelay(SYS_DELAY_1US*30);//wait for writting next byte
	
	I2C_SendByte(I2C_Channel, lData);
	nTemp = I2CGetACK(I2C_Channel);
	if (!nTemp)
	{
		  lRt =  false;     // slave no ack
		  return lRt;
	}
	
	SysCtlDelay(SYS_DELAY_1US*30);//wait for writting next byte
	
	I2CStop(I2C_Channel);
	return lRt;
}




bool Max5417Setting(uint8_t lChannel, uint8_t lAddress, uint8_t lRegister, uint8_t lValue)
{	
	bool lRt = true;

	lRt = MAX5417_WriteData(lChannel, lAddress, lRegister, lValue);

	return lRt;
}



