
#ifndef ETH_HTTP_H_
#define ETH_HTTP_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
// #include "lwip/dns.h"
#include "eth_client.h"
#include "json.h"
#include "EepromControl.h"



extern char g_cAppRequest1[2000];

static const char g_cMode[] = "";

static char g_cAPPID[] = "";

static char g_DataArray[] = "&sXXXXXX=0000000000000000";

static char g_MachineStatus[] = "XXXXXXXXXXXXXXX";

static const char g_NetHeader_Server[] = "GET http://119.23.71.36:7515/Service.asmx/GetString?";
static const char g_NetHeader_Customer[] = "GET http://10.199.89.216:7515/Service.asmx/GetString?";

static char g_cHTTP11[] = " HTTP/1.0\r\n\r\n";

static char g_cDNS_Server[] = "119.23.71.36";
static char g_cDNS_Customer[] = "10.199.89.216";

static const char g_cDNSNet[] = "";


static uint32_t g_sPort = 7515;

void SettingMachineStatus(uint8_t lStatus);
void UpdateTimer(uint16_t lTimer);
char *itoa(int n,char str[]);

void CharArrayCreation(void);
uint8_t BBC_Check(char *pStr);

#endif




