/*
 * TT_ADXL_345.h
 *
 *  Created on: May 19, 2023
 *      Author: talha
 */

#ifndef INC_TT_ADXL_345_H_
#define INC_TT_ADXL_345_H_
#include "stm32f4xx_hal.h"
#include <math.h>
extern I2C_HandleTypeDef hi2c1;

#define ADXL_ADDRESS 0xA6
#define PI 3.141592654
void TT_ADXL_Init();
void TT_ADXL_Write(uint8_t reg, uint8_t value);
void TT_ADXL_Read(uint8_t reg, uint8_t numberOfBytes);
void TT_GET_ACCELERATIONS(void);
float TT_GET_X_TILT_ANGLE(void);
float TT_GET_Y_TILT_ANGLE(void);

#endif /* INC_TT_ADXL_345_H_ */
