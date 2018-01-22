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
#if (DEBUG_LOG_ENABLE)
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
#endif /* DEBUG_LOG_ENABLE */
/* Private functions ---------------------------------------------------------*/

/*
 * @brief  BSP Initialization.
 * @param  None
 * @retval BSP Init status.
 */
HAL_StatusTypeDef BSP_Init(void)
{
	HAL_StatusTypeDef ret = HAL_OK;
	if((ret = Board_GPIOs_Init()) != HAL_OK) return ret;
	if((ret = Board_UARTs_Init()) != HAL_OK) return ret;
	return ret;
}

#if (DEBUG_LOG_ENABLE)
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
	DEBUG_PORT_SEND_BYTE(ch);
  return ch;
}
#endif /* DEBUG_LOG_ENABLE */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
