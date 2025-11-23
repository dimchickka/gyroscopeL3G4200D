#include "W25Q32JV.h"


static inline void csLOW(){
    HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
}

static inline void csHIGH(){
    HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
}

void W25Q_Reset(SPI_HandleTypeDef *hspi){
    uint8_t buf[2];
    buf[0] = 0x66; //enable Reset
    buf[1]= 0x99; //reser
    csLOW();
    uint8_t sizeOfBytes = 2;
    HAL_SPI_Transmit(hspi, buf, sizeOfBytes, HAL_MAX_DELAY);
    csHIGH();
    HAL_Delay(100);
}

uint32_t W25Q_ReadID(SPI_HandleTypeDef *hspi){
    uint8_t tData = 0x9F; //Read JEDEC ID
    uint8_t sizeOfTransmittingDataBytes = 1;
    uint8_t buf[3];
    uint8_t sizeOfRceiveingDataBytes = 3;
    csLOW();
    HAL_SPI_Transmit(hspi, &tData, sizeOfTransmittingDataBytes, SPI_TIMEOUT_MS);
    HAL_SPI_Receive(hspi, buf,sizeOfRceiveingDataBytes, SPI_TIMEOUT_MS);
    csHIGH();
    return((buf[0] << 16) | (buf[1] << 8) | buf[2]);
}

