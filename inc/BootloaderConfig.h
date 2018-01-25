/**
  ******************************************************************************
  * @file    BootloaderConfig.h
  * @author  kyChu
  * @version V1.0
  * @date    23-January-2018
  * @brief   Boot loader global configuration.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOOTLOADERCONFIG_H
#define __BOOTLOADERCONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported definitions ------------------------------------------------------*/
/* User Application start address */
#define APPLICATION_START_ADDRESS                (0x08010000)

/* User Application RAM region */
#define APPLICATION_RAM_REGION_ORIGIN            (0x20000000) /* begin of RAM */
#define APPLICATION_RAM_REGION_END               (0x20050000) /* end of RAM */

/* FAT12 file system */
#define BOOT_TABLE_EDITABLE                      (0)       /* format operation */
#define README_FILE_EDITABLE                     (0)

/* Exported macros -----------------------------------------------------------*/
/* Debug enable */
#define DEBUG_LOG_ENABLE                         (0)
#if (DEBUG_LOG_ENABLE)
  #define DEBUG(...)                             printf(__VA_ARGS__); \
                                                 printf("\n");
#else
  #define DEBUG(...)
#endif /* DEBUG_LOG_ENABLE */

#endif /* __BOOTLOADERCONFIG_H */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
