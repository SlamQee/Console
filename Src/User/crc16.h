
#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


uint16_t GetCRC16(uint8_t *ptr, uint8_t len);
bool CheckCRC(uint8_t *ptr, uint8_t len);
void SendCRC(void);

#endif




