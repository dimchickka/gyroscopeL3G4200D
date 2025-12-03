#include "main.h"

bool testMemory = true; //set "true" if you want to test memory chip only

int main(void){
    
    MCU_Init();
    if(Gyro_Init(&hi2c1, &huart1) == ERROR){isErrorFlag = 1;}
    GyroData_t gyroData = {0}; 
    HAL_Delay(STEP_TO_READ_MS);
    
    while (1){
            if(!testMemory){
                if(isErrorFlag == 1){
                //We will just blink
                blinkTheDiod(LED_GREEN_PORT, LED_GREEN_PIN);
                }
                else{
                    startGettingData(&hi2c1,&huart1, &gyroData);
                }
                
                HAL_Delay(STEP_TO_READ_MS);
            }
            else{
                W25Q_Reset(&hspi1);
                uint32_t ID = W25Q_ReadID(&hspi1);
                char msg[20];
                sprintf(msg, "ID: %06lX\r\n", (unsigned int)ID);   // формат 3 байта, HEX
                HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
            }
    }
}

