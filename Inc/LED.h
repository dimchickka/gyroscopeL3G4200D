#ifndef LED_H_
#define LED_H_

#include "stm32f1xx_hal.h"

void blinkTheDiod(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif /* LED_H_ */
