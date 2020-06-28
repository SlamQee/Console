
#ifndef ETH_CLIENT_H_
#define ETH_CLIENT_H_

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

//*****************************************************************************
//
// Events passed back to the application.
//
//*****************************************************************************
#define ETH_EVENT_RECEIVE       0x00000001
#define ETH_EVENT_CONNECT       0x00000002
#define ETH_EVENT_DISCONNECT    0x00000003
#define ETH_EVENT_CLOSE         0x00000004
#define ETH_EVENT_INVALID_REQ   0x00000005

//*****************************************************************************
//
// 访问的默认连接.
//
//*****************************************************************************
typedef enum
{
    //
    // 139.129.12.49.
    //
    defaultUrl
}
tNetSource;

//*****************************************************************************
//
// 响应的默认参数对象.
//
//*****************************************************************************
typedef struct
{
    //
    // The brief App description, this is caller provided.
    //
    const char *pcDescription;

    //
    // The last time these values were update (GMT Unix time).
    //
    uint32_t ui32Time;     
}
tResponseContent;

//*****************************************************************************
//
// The type definition for event functions.
//
//*****************************************************************************
typedef void (* tEventFunction)(uint32_t ui32Event, void* pvData,
                                uint32_t ui32Param);

//*****************************************************************************
//
// Exported Ethernet function prototypes.
//
//*****************************************************************************
extern void EthClientInit(tEventFunction pfnEvent);
extern void EthClientProxySet(const char *pcProxyName);
extern void EthClientTick(uint32_t ui32TickMS);
extern uint32_t EthClientAddrGet(void);
extern void EthClientMACAddrGet(uint8_t *pui8Addr);
extern uint32_t EthClientServerAddrGet(void);
extern void EthClientReset(void);
void EthClientTCPDisconnect(void);

//*****************************************************************************
//
// Exported App related prototypes.
//
//*****************************************************************************
extern void ApplicationSourceSet(tNetSource eDefaultUrl);
extern int32_t ApplicationRequest2(tNetSource eDefaultUrl,
                              const char *pcQuery,
                              tResponseContent *psResponseContent,
                              tEventFunction pfnEvent);
extern int32_t ApplicationRequest1(tNetSource eDefaultUrl,
                               const char *pcQuery,
                               tResponseContent *psResponseContent,
                               tEventFunction pfnEvent);

#ifdef __cplusplus
}
#endif

#endif
