

#ifndef __DRIVERS_PINOUT_H__
#define __DRIVERS_PINOUT_H__

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
// Define Board LED's
//
//*****************************************************************************
#define CLP_D1              1
#define CLP_D2              2
#define CLP_D3              4
#define CLP_D4              8

#define CLP_D1_PORT         GPIO_PORTN_BASE
#define CLP_D1_PIN          GPIO_PIN_1

#define CLP_D2_PORT         GPIO_PORTN_BASE
#define CLP_D2_PIN          GPIO_PIN_0

#define CLP_D3_PORT         GPIO_PORTF_BASE
#define CLP_D3_PIN          GPIO_PIN_4

#define CLP_D4_PORT         GPIO_PORTF_BASE
#define CLP_D4_PIN          GPIO_PIN_0

//*****************************************************************************
//
// Prototypes.
//
//*****************************************************************************
extern void PinoutSet(bool bEthernet, bool bUSB);
extern void LEDWrite(uint32_t ui32LEDMask, uint32_t ui32LEDValue);
extern void LEDRead(uint32_t *pui32LEDValue);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERS_PINOUT_H__