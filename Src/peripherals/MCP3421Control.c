//*****************************************************************************
//
//
//
//*****************************************************************************

#include "mcp3421control.h"
#include "my_iic.h"


uint8_t MCP3421_WriteData(uint8_t I2C_Channel, uint8_t Reg)
{
	uint8_t lRt = 0, nTemp;

	I2CStart(I2C_Channel);				 //IIC startup;
	I2C_SendByte(I2C_Channel, 0xD2);
	nTemp = I2CGetACK(I2C_Channel);
	if (!nTemp)
	{
		  lRt =  false; 	// slave no ack
		  return lRt;
	}
	SysCtlDelay(SYS_DELAY_1US*10);//wait for writting next byte

	I2C_SendByte(I2C_Channel, Reg);
	nTemp = I2CGetACK(I2C_Channel);
	if (!nTemp)
	{
		  lRt =  false; 	// slave no ack
		  return lRt;
	}
	
	SysCtlDelay(SYS_DELAY_1US*10);//wait for writting next byte

	return 1;
}



uint32_t MCP3421_ReadData(uint8_t I2C_Channel)
{
	uint8_t lRt = 0, nTemp, i;

	uint32_t tempData, value;

	I2CStart(I2C_Channel);
	
	I2C_SendByte(I2C_Channel, 0xD3);
	nTemp = I2CGetACK(I2C_Channel);
	if (!nTemp)
	{
		  lRt =  false;     // slave no ack
		  return lRt;
	}
	SysCtlDelay(SYS_DELAY_1US*10);//wait for next byte

	for(i = 0; i < 3; i++)
	{
		tempData  = I2C_ReadByte(I2C_Channel);
		SysCtlDelay(SYS_DELAY_1US*10);//wait for next byte
		if(i!=2) 
		{
			I2CSetACK(I2C_Channel);
		}
		value = (value<<8)|tempData;
		value &= 0x03ffff;
	}
	
	SysCtlDelay(SYS_DELAY_1US*10);//wait for next byte

	I2CSetNACK(I2C_Channel);

	I2CStop(I2C_Channel);

	return value;

}



uint32_t GetCurrrent(uint8_t I2C_Channel)
{
	uint32_t current;

	MCP3421_WriteData(I2C_Channel,0xd2);

	current = MCP3421_ReadData(I2C_Channel);

	return current;
}


