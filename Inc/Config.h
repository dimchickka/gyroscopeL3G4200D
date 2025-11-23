#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h> 
#include <string.h> 
#include <stdbool.h>
#include <stdio.h>

void SystemClock_Config(void);
void Error_Handler(void);
void MCU_Init(void);

#define SUCCESS_EXECUTION 0
#define ERROR_EXECUTION 1

extern uint8_t isErrorFlag;
extern bool isFirstStep;

#endif
