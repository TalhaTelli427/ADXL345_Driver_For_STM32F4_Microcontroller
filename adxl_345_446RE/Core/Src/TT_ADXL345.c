/*
 * TT_ADXL345.c
 *
 *  Created on: May 19, 2023
 *      Author: talha
 */
#include "TT_ADXL_345.h"
uint8_t i;
uint8_t data_rec[6];
int16_t x, y, z;
float xg, yg, zg, angle_x, angle_y;

void TT_ADXL_Write(uint8_t reg, uint8_t value) {
	uint8_t data[2] = { 0 };
	data[0] = reg;
	data[1] = value;
	HAL_I2C_Master_Transmit(&hi2c1, ADXL_ADDRESS, data, 2, 100);
}

void TT_ADXL_Read(uint8_t reg, uint8_t numberOfBytes) {
	HAL_I2C_Mem_Read(&hi2c1, ADXL_ADDRESS, reg, 1, data_rec, numberOfBytes,
			100);

}

void TT_ADXL_Init() {
	TT_ADXL_Read(0x00, 1);
	TT_ADXL_Write(0x2D, 0);
	TT_ADXL_Write(0x2D, 0x08);
	TT_ADXL_Write(0x31, 0x01);
}
void TT_GET_ACCELERATIONS(void) {

	TT_ADXL_Read(0x32, 6);
	x = (data_rec[1] << 8) | data_rec[0];
	y = (data_rec[3] << 8) | data_rec[2];
	z = (data_rec[5] << 8) | data_rec[4];
	xg = x * .0078;
	yg = y * .0078;
	zg = z * .0078;

}
float TT_GET_X_TILT_ANGLE(void) {
	TT_GET_ACCELERATIONS();
	angle_x = atan2(xg, zg);
	angle_x = angle_x * 180.0 / PI;
	return angle_x;

}
float TT_GET_Y_TILT_ANGLE(void) {
	TT_GET_ACCELERATIONS();
	angle_y = atan2(yg, zg);
	angle_y = angle_y * 180.0 / PI;
	return angle_y;

}
