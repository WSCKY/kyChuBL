#ifndef __BOOTLOADERCONFIG_H
#define __BOOTLOADERCONFIG_H

#include "stm32f7xx.h"

/* User Application start address */
#define APPLICATION_START_ADDRESS                (0x08008000)

/* Debug enable */
#define DEBUG_LOG_ENABLE                         (0)
#if (DEBUG_LOG_ENABLE)
  #define DEBUG(...)                             printf(__VA_ARGS__); \
                                                 printf("\n");
#else
  #define DEBUG(...)
#endif /* DEBUG_LOG_ENABLE */

#endif /* __BOOTLOADERCONFIG_H */
