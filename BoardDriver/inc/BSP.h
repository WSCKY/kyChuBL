/**
  ******************************************************************************
  * @file    BSP.h
  * @author  kyChu
  * @version V1.0
  * @date    22-January-2018
  * @brief   Header file for BSP.c.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_H
#define __BSP_H

/* Includes ------------------------------------------------------------------*/
#include "Board_GPIOs.h"
#include "Board_UARTs.h"

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported definitions ------------------------------------------------------*/
#if (DEBUG_LOG_ENABLE)
#define DEBUG_PORT_SEND_BYTE                     Uart7PushOneByte
#endif /* DEBUG_LOG_ENABLE */
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
HAL_StatusTypeDef BSP_Init(void);

#endif /* __BSP_H */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
