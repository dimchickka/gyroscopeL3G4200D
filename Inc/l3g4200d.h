#ifndef L3G4200D_H
#define L3G4200D_H

#include "stm32f1xx_hal.h"
#include "Config.h"


//registors
#define L3G4200D_ADDRESS 0x68 << 1 //if SDO = LOW 
#define L3G4200D_WhO_AM_I 0x0F
#define L3G4200D_CTRL_REG1 0x20
#define L3G4200D_CTRL_REG4 0x23
#define L3G4200D_OUT_X_L 0x28
#define I2C_TIMEOUT_MS 10  // мс
#define UART_TIMEOUT_MKS 10  // мкс
#define STEP_TO_READ_MS 100 // мс
#define STEP_TO_READ_S 0.10f // с

// Configuration values
#define L3G4200D_CTRL_REG1_CONFIG 0x7F // Normal mode, all axes enabled, 200Hz, 70Hz cutoff
#define L3G4200D_CTRL_REG4_CONFIG 0x00  // 250 dps full scale

typedef struct {
    int16_t x_prev, y_prev, z_prev;
    int16_t x_current, y_current, z_current;
    float ax, ay, az;   // угловое ускорение
} GyroData_t;


uint8_t Gyro_Init(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef* huart);
void Gyro_Read_Velocity(I2C_HandleTypeDef *hi2c, GyroData_t* data);
void prepareStructure(GyroData_t* data);
void calculateAcceleration(GyroData_t* data, float DT);
void startGettingData(I2C_HandleTypeDef *hi2c,UART_HandleTypeDef* huart, GyroData_t* data);
void Gyro_Configure(I2C_HandleTypeDef *hi2c);
#endif