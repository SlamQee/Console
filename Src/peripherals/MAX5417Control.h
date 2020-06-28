/*
 * MAX5417.h
 *
 *  Created on: 2017Äê4ÔÂ12ÈÕ
 *      Author: lenovo
 */

#ifndef MAX5417CONTROL_H_
#define MAX5417CONTROL_H_

#include "stdint.h"
#include "stdbool.h"

//define IIC CAHNNEL to lamp channel
#define  R_UP_LAMP_CHANNEL     1  
#define  R_DN_LAMP_CHANNEL     2  
#define  G_UP_LAMP_CHANNEL     3  
#define  G_DN_LAMP_CHANNEL     4 
#define  B_UP_LAMP_CHANNEL     5  
#define  B_DN_LAMP_CHANNEL     10  

//define Command byte
#define  VREG         0x11
#define  NVREG        0x21
#define  NVREGxVREG   0x61
#define  VREGxNVREG   0x51


bool MAX5417_WriteData(uint8_t I2C_Channel, uint8_t lAddress, uint8_t lRegister, uint8_t lData);

bool Max5417Setting(uint8_t lChanel, uint8_t lAddress, uint8_t lRegister, uint8_t lValue);



#endif /* MAX5417CONTROL_H_ */


