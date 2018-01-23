/**
  ******************************************************************************
  * @file    BootloaderMaths.h
  * @author  kyChu
  * @version V1.0
  * @date    23-January-2018
  * @brief   Boot loader global macros, functions and types.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOOTLOADERMATHS_H
#define __BOOTLOADERMATHS_H

/* Includes ------------------------------------------------------------------*/
#include "BootloaderConfig.h"

#define __LOBYTE(x)                    ((uint8_t)((x) & 0x00FF))
#define __HIBYTE(x)                    ((uint8_t)(((x) & 0xFF00) >>8))

/* File Time --------------------------------------------------------------- */
#define FILE_DATE(y, m, d)             (((((uint16_t)(y) - 1980) & 0x7F) << 9) | \
                                       (((uint16_t)(m) & 0x0F) << 5) | \
									   (((uint16_t)(d) & 0x1F) << 0))

#define FILE_TIME(h, m, s)             ((((uint16_t)(h) & 0x1F) << 11) | \
                                       (((uint16_t)(m) & 0x3F) << 5) | \
									   (((uint16_t)(s >> 1) & 0x1F) << 0))

/* File Size --------------------------------------------------------------- */
#define _FILE_SIZE_BYTE1_(s)           ((uint8_t)(((s) & 0x000000FF) >> 0))
#define _FILE_SIZE_BYTE2_(s)           ((uint8_t)(((s) & 0x0000FF00) >> 8))
#define _FILE_SIZE_BYTE3_(s)           ((uint8_t)(((s) & 0x00FF0000) >> 16))
#define _FILE_SIZE_BYTE4_(s)           ((uint8_t)(((s) & 0xFF000000) >> 24))

#endif /* __BOOTLOADERMATHS_H */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
