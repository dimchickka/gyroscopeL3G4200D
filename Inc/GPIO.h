#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f1xx_hal.h"

///*===========================================================
// *  Пользовательские define-ы пинов
// *  Добавляем свои пины здесь
// *===========================================================*/

//// Пример: Светодиоды
//#define LED_GREEN_PORT      GPIOA
//#define LED_GREEN_PIN       GPIO_PIN_0

//#define LED_BLUE_PORT       GPIOA
//#define LED_BLUE_PIN        GPIO_PIN_1

//// Пример: USART (если нужно)
//#define USART6_TX_PORT      GPIOC
//#define USART6_TX_PIN       GPIO_PIN_6
//#define USART6_TX_AF        GPIO_AF8_USART6

//// Пример: Мотор 0
//#define MOT0_PORT           GPIOB
//#define MOT0_PINS           (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)

//// Пример: Мотор 1
//#define MOT1_PORT           GPIOB
//#define MOT1_PINS           (GPIO_PIN_4 | GPIO_PIN_5)

///*===========================================================*/

#define LED_GREEN_PORT      GPIOC
#define LED_GREEN_PIN       GPIO_PIN_13


#define USART1_TX_PORT      GPIOA
#define USART1_TX_PIN       GPIO_PIN_9
#define USART1_RX_PORT      GPIOA
#define USART1_RX_PIN       GPIO_PIN_10


#define I2C1_PORT    GPIOB
#define I2C1_SCL_PIN GPIO_PIN_6
#define I2C1_SDA_PIN GPIO_PIN_7


static void GPIO_EnableClocks(void);
void GPIO_Init_All(void);

#endif /* GPIO_H_ */
