#include "GPIO.h"

/* ===========================================================
 * Включение тактирования GPIO
 * =========================================================== */
static void GPIO_EnableClocks(void)
{
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();  //для usart1 и для SPI
    
    __HAL_RCC_GPIOB_CLK_ENABLE(); //для hi2c1  pins PB6 and PB7
    __HAL_RCC_GPIOC_CLK_ENABLE();
    // добавляем при необходимости
}

void GPIO_Init_All(void){
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* ---------- Включаем тактирование ---------- */
    GPIO_EnableClocks();


    /* =======================================================
     *                LED GREEN
     * ======================================================= */
    GPIO_InitStruct.Pin = LED_GREEN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GREEN_PORT, &GPIO_InitStruct);
    
    
    
    /* === USART1 TX === */
    GPIO_InitStruct.Pin = USART1_TX_PIN;    // PA9
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; // Альтернативная функция push-pull
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(USART1_TX_PORT, &GPIO_InitStruct);

    /* === USART1 RX === */
    GPIO_InitStruct.Pin = USART1_RX_PIN;   // PA10
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT; // Вход для RX
    GPIO_InitStruct.Pull = GPIO_NOPULL;     // без подтяжки
    HAL_GPIO_Init(USART1_RX_PORT, &GPIO_InitStruct);



    /* === I2C1 SCL/SDA === */
    GPIO_InitStruct.Pin = I2C1_SCL_PIN | I2C1_SDA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;    // Open-drain для I2C
    GPIO_InitStruct.Pull = GPIO_PULLUP;        // подтяжка к VCC
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(I2C1_PORT, &GPIO_InitStruct);
    
    
        /* SPI1 SCK и MOSI */
    GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* SPI1 MISO */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Если используем программный CS */
    GPIO_InitStruct.Pin = GPIO_PIN_4; // например PA4
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
}











///* ===========================================================
// * Инициализация GPIO
// * =========================================================== */
//void GPIO_Init_All(void)
//{
//    GPIO_InitTypeDef GPIO_InitStruct = {0};

//    /* ---------- Включаем тактирование ---------- */
//    GPIO_EnableClocks();


//    /* =======================================================
//     *                LED GREEN
//     * ======================================================= */
//    GPIO_InitStruct.Pin = LED_GREEN_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(LED_GREEN_PORT, &GPIO_InitStruct);


//    /* =======================================================
//     *                LED BLUE
//     * ======================================================= */
//    GPIO_InitStruct.Pin = LED_BLUE_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    HAL_GPIO_Init(LED_BLUE_PORT, &GPIO_InitStruct);


//    /* =======================================================
//     *                Motor 0 pins
//     * ======================================================= */
//    GPIO_InitStruct.Pin = MOT0_PINS;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(MOT0_PORT, &GPIO_InitStruct);


//    /* =======================================================
//     *                Motor 1 pins
//     * ======================================================= */
//    GPIO_InitStruct.Pin = MOT1_PINS;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    HAL_GPIO_Init(MOT1_PORT, &GPIO_InitStruct);


//    /* =======================================================
//     *                USART6 TX pin
//     * ======================================================= */
//    GPIO_InitStruct.Pin = USART6_TX_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(USART6_TX_PORT, &GPIO_InitStruct);
//}
