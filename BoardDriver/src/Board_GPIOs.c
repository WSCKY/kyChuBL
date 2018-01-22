/**
  ******************************************************************************
  * @file    Board_GPIOs.c
  * @author  kyChu
  * @version V0.1
  * @date    22-January-2018
  * @brief   Board GPIO Peripheral Driver.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "Board_GPIOs.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static GPIO_InitDataType GPIO_InitTable[GPIO_INIT_QTY] = GPIO_PORT_INIT_TABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*
 * @brief  Initializes Board GPIOs.
 * @param  None
 * @retavl HAL Status.
 */
HAL_StatusTypeDef Board_GPIOs_Init(void)
{
	uint8_t i = 0;
	GPIO_InitTypeDef  GPIO_InitStruct;
	/* -1- Enable GPIO Clock (to be able to program the configuration registers). */
	GPIO_PORT_CLK_ENABLE_ALL();
	for(; i < GPIO_INIT_QTY; i ++) {
		/* -2- Configure IO in specified mode. */
		GPIO_InitStruct.Pin = GPIO_InitTable[i].GPIO_PIN;
		GPIO_InitStruct.Mode = GPIO_InitTable[i].GPIO_MODE;
		GPIO_InitStruct.Pull = GPIO_InitTable[i].GPIO_PULL;
		GPIO_InitStruct.Speed = GPIO_InitTable[i].GPIO_SPEED;
		HAL_GPIO_Init(GPIO_InitTable[i].GPIO_PORT, &GPIO_InitStruct);
		/* -3- Set GPIO Pin to default state. */
		HAL_GPIO_WritePin(GPIO_InitTable[i].GPIO_PORT, GPIO_InitTable[i].GPIO_PIN, GPIO_InitTable[i].PinState);
	}
	return HAL_OK;
}

/*
 * @brief  set GPIO pin to high.
 * @param  pin number.
 * @retval None
 */
void Board_GPIO_SetLevelHigh(uint8_t n)
{
	GPIO_InitTable[n].GPIO_PORT->BSRR = GPIO_InitTable[n].GPIO_PIN;
}

/*
 * @brief  set GPIO pin to low.
 * @param  pin number.
 * @retval None
 */
void Board_GPIO_SetLevelLow(uint8_t n)
{
	GPIO_InitTable[n].GPIO_PORT->BSRR = (uint32_t)(GPIO_InitTable[n].GPIO_PIN) << 16;
}

/*
 * @brief  Toggle GPIO pin level.
 * @param  pin number.
 * @retval None
 */
void Board_GPIO_SetLevelToggle(uint8_t n)
{
	GPIO_InitTable[n].GPIO_PORT->ODR ^= GPIO_InitTable[n].GPIO_PIN;
}

/*
 * @brief  Reads the specified input port pin.
 * @param  pin number.
 * @retval The input port pin value.
 */
GPIO_PinState Board_GPIO_ReadLevel(uint8_t n)
{
	return ((GPIO_InitTable[n].GPIO_PORT->IDR & GPIO_InitTable[n].GPIO_PIN) != (uint32_t)GPIO_PIN_RESET);
}

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
