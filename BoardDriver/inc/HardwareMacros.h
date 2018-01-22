/**
  ******************************************************************************
  * @file    HardwareMacros.h
  * @author  kyChu
  * @version V1.0
  * @date    22-January-2018
  * @brief   this file provides hardware layer derive macros.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HARDWAREMACROS_H
#define __HARDWAREMACROS_H

/* Includes ------------------------------------------------------------------*/
#include "BSP.h"

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported definitions ------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Power Control Driver */
#define BOARD_POWER_ON()                         Board_GPIO_SetLevelHigh(1)
#define BOARD_POWER_OFF()                        Board_GPIO_SetLevelLow(1)
#define BOARD_POWER_KEY_STATE()                  Board_GPIO_ReadLevel(0)

/* LED Driver */
#define LED_RED_ON()                             Board_GPIO_SetLevelHigh(4)
#define LED_RED_OFF()                            Board_GPIO_SetLevelLow(4)
#define LED_RED_TOG()                            Board_GPIO_SetLevelToggle(4)

#define LED_BLUE_ON()                            Board_GPIO_SetLevelHigh(3)
#define LED_BLUE_OFF()                           Board_GPIO_SetLevelLow(3)
#define LED_BLUE_TOG()                           Board_GPIO_SetLevelToggle(3)

#define LED_GREEN_ON()                           Board_GPIO_SetLevelHigh(2)
#define LED_GREEN_OFF()                          Board_GPIO_SetLevelLow(2)
#define LED_GREEN_TOG()                          Board_GPIO_SetLevelToggle(2)
/* Exported functions ------------------------------------------------------- */

#endif /* __HARDWAREMACROS_H */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
