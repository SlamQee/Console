
#ifndef __DS18B20_H__
#define __DS18B20_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

typedef struct 
{
	uint8_t Head;
	uint8_t Len;
	uint8_t Addr;
	uint8_t Cmd;
	uint8_t Check;
	uint8_t Tail[4];
}
TEMP_ALLCH_DATA;


typedef struct 
{
	uint8_t Head;
	uint8_t Len;
	uint8_t Addr;
	uint8_t Cmd;
	uint8_t Channel;
	uint8_t Check;
	uint8_t Tail[4];
}
TEMP_SINGLECH_DATA;

void TempDet_CmdAnalysis(uint8_t *pStr, uint8_t len);
void TempDet_CmdProc(uint8_t *CmdBuf, uint8_t len);
void TempDet_ReadAll(void);
void TempDet_ReadSingle(uint8_t Channel);
short RegToData(uint8_t *RegByte);

#endif




