/**
  ******************************************************************************
  * @file    Board_GPIOs.h
  * @author  kyChu
  * @version V0.1
  * @date    22-January-2018
  * @brief   Header file for Board GPIO Driver.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOARD_GPIOS_H
#define __BOARD_GPIOS_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx.h"
#include "PeriphDefine.h"

/* Exported types ------------------------------------------------------------*/
typedef struct {
	GPIO_TypeDef *GPIO_PORT;
	uint32_t GPIO_PIN;
	uint32_t GPIO_MODE;
	uint32_t GPIO_PULL;
	uint32_t GPIO_SPEED;
	GPIO_PinState PinState;
} GPIO_InitDataType;
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported definitions ------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
#define GPIO_INIT_QTY                            (14)

#define GPIO_PORT_INIT_TABLE                     {{GPIOB, GPIO_PIN_0, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_HIGH, GPIO_PIN_RESET}, \
	                                              {GPIOB, GPIO_PIN_1, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
                                                  {GPIOD, GPIO_PIN_14, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
	                                              {GPIOD, GPIO_PIN_15, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
	                                              {GPIOE, GPIO_PIN_15, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOA, GPIO_PIN_0, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOA, GPIO_PIN_1, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOA, GPIO_PIN_2, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOA, GPIO_PIN_3, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOA, GPIO_PIN_15, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOB, GPIO_PIN_3, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOB, GPIO_PIN_10, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOB, GPIO_PIN_11, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_PIN_RESET}, \
												  {GPIOA, GPIO_PIN_9, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_HIGH, GPIO_PIN_RESET}}

#define GPIO_PORT_CLK_ENABLE_ALL()               {__HAL_RCC_GPIOA_CLK_ENABLE(); \
	                                              __HAL_RCC_GPIOB_CLK_ENABLE(); \
	                                              __HAL_RCC_GPIOC_CLK_ENABLE(); \
	                                              __HAL_RCC_GPIOD_CLK_ENABLE(); \
	                                              __HAL_RCC_GPIOE_CLK_ENABLE(); \
	                                              __HAL_RCC_GPIOF_CLK_ENABLE(); }

/* Exported functions ------------------------------------------------------- */
HAL_StatusTypeDef Board_GPIOs_Init(void);
void Board_GPIO_SetLevelLow(uint8_t n);
void Board_GPIO_SetLevelHigh(uint8_t n);
void Board_GPIO_SetLevelToggle(uint8_t n);
GPIO_PinState Board_GPIO_ReadLevel(uint8_t n);

#endif /* __BOARD_GPIOS_H */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
