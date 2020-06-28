
#ifndef _MY_WATCHDOG_H__
#define _MY_WATCHDOG_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


#define FEED_DOG        (g_bFeedWatchdog = 1)

void My_WatchdogInit(uint8_t TimerSec);
void FeedWatchDog(void);

#endif




