

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "user_def.h"

#ifdef DEBUG_OUTPUT
//#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#define DebugPrintf(...)        UARTprintf(__VA_ARGS__)
#else
#define DebugPrintf(...)
#endif
#else
//#define DebugPrintf(...)

#endif
