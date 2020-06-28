

#ifndef __JSON_H__
#define __JSON_H__

#include <stdint.h>
#include <stdbool.h>
#include "eth_client.h"
#include "lwip\pbuf.h"


#define NETWORKDEBUG		1

#define INVALID_INT             ((int32_t)(0x80000000))

extern int32_t JSONParse2(uint32_t ui32Index, tResponseContent *psResponseContent, struct pbuf *psBuf);
extern int32_t JSONParse1(uint32_t ui32Index, tResponseContent *psResponseContent, struct pbuf *psBuf);

#endif


