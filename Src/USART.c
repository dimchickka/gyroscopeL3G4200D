#include "USART.h"

/* ===========================================================
 * Объекты для HAL UART
 * =========================================================== */
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* ===========================================================
 * Включение тактирования UART и GPIO для TX/RX
 * =========================================================== */
static void UART_EnableClocks(void)
{
    __HAL_RCC_USART1_CLK_ENABLE();
//    __HAL_RCC_USART2_CLK_ENABLE();
//    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE(); // Для USART1/2
//    __HAL_RCC_GPIOB_CLK_ENABLE(); // Для USART3
}

/* ===========================================================
 * Инициализация UART
 * =========================================================== */
void UART_Init_All(void)
{
    UART_EnableClocks();

    /* -------------------- USART1 -------------------- */
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }

//    /* -------------------- USART2 -------------------- */
//    huart2.Instance = USART2;
//    huart2.Init.BaudRate = 115200;
//    huart2.Init.WordLength = UART_WORDLENGTH_8B;
//    huart2.Init.StopBits = UART_STOPBITS_1;
//    huart2.Init.Parity = UART_PARITY_NONE;
//    huart2.Init.Mode = UART_MODE_TX_RX;
//    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

//    if (HAL_UART_Init(&huart2) != HAL_OK)
//    {
//        Error_Handler();
//    }

//    /* -------------------- USART3 -------------------- */
//    huart3.Instance = USART3;
//    huart3.Init.BaudRate = 115200;
//    huart3.Init.WordLength = UART_WORDLENGTH_8B;
//    huart3.Init.StopBits = UART_STOPBITS_1;
//    huart3.Init.Parity = UART_PARITY_NONE;
//    huart3.Init.Mode = UART_MODE_TX_RX;
//    huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//    huart3.Init.OverSampling = UART_OVERSAMPLING_16;

//    if (HAL_UART_Init(&huart3) != HAL_OK)
//    {
//        Error_Handler();
//    }
}
