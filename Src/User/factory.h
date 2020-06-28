
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


typedef enum
{
	TEST_PRJ_PORT,
	TEST_TEMP_PORT,
	TEST_CHILLER_PORT,
	TEST_LUX_PORT,
	TEST_DRV_PORT,
	TEST_NET_PORT

}TEST_ITEM;


void FactoryCmdAnalysis(uint8_t *pStr, uint8_t len);
void FactoryCmdProc(uint8_t *CmdBuf, uint8_t len);

void AutoTestMode(void);
void AutoTestReset(void);

#endif




