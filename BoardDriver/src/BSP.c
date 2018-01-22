/**
  ******************************************************************************
  * @file    BSP.c
  * @author  kyChu
  * @version V1.0
  * @date    22-January-2018
  * @brief   Board Support Package Driver.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "BSP.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*
 * @brief  BSP Initialization.
 * @param  None
 * @retval BSP Init status.
 */
HAL_StatusTypeDef BSP_Init(void)
{
	HAL_StatusTypeDef ret = HAL_OK;
	ret = Board_GPIOs_Init();
	return ret;
}

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
