#ifndef W25Q32JV_H_
#define W25Q32JV_H_

#include "stm32f1xx_hal.h"
#include "SPI.h"
#include "Config.h"

#define CS_PORT GPIOA
#define CS_PIN GPIO_PIN_4
#define SPI_TIMEOUT_MS 10 


// Объявляем хэндлы I2C
extern I2C_HandleTypeDef hi2c1;
//extern I2C_HandleTypeDef hi2c2;

// Функция инициализации всех I2C
void W25Q_Reset(SPI_HandleTypeDef *hspi);
uint32_t W25Q_ReadID(SPI_HandleTypeDef *hspi);


#endif /* W25Q32JV_H_ */