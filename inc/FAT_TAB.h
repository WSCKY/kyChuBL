/**
  ******************************************************************************
  * @file    FAT_TAB.h
  * @author  kyChu
  * @version V1.0
  * @date    23-January-2018
  * @brief   FAT12 file system data structure.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FAT_TAB_H
#define __FAT_TAB_H

/* Includes ------------------------------------------------------------------*/
#include "BootloaderMaths.h"

/* File Attributes --------------------------------------------------------- */
#define FILE_ATTRIBUTES_RWE            0x00      /* Read Write */
#define FILE_ATTRIBUTES_RDO            0x01      /* Read only */
#define FILE_ATTRIBUTES_HID            0x02      /* Hidden */
#define	FILE_ATTRIBUTES_SYS	           0x04      /* System */
#define	FILE_ATTRIBUTES_VOL            0x08      /* Volume label */
#define FILE_ATTRIBUTES_LFN            0x0F      /* LFN entry */
#define FILE_ATTRIBUTES_DIR            0x10      /* Directory */
#define FILE_ATTRIBUTES_ARC            0x20      /* Archive */
#define FILE_ATTRIBUTES_MASK           0x3F      /* Mask of defined bits */

/* FATFS ERROR ------------------------------------------------------------- */
#define FATFS_OK                       (0)
#define FATFS_ERROR                    (-1)

/* FATFS DUMMY BYTE -------------------------------------------------------- */
#define RESERVED_BYTE                  ((uint8_t)0x00)

/* SECTOR SIZE ------------------------------------------------------------- */
#define SECTOR_SIZE                    ((uint32_t)0x200)
#define SECTOR_IDX_TO_ADDR(idx)        ((idx) << 9)
#define SECTORS_CONV_BYTES(sec)        (SECTOR_IDX_TO_ADDR(sec))
#define BYTES_CONV_SECTORS(num)        ((num) >> 9)

#define FATFS_TOTAL_SECTORS            (9)
#define FATFS_USED_SIZE                (SECTORS_CONV_BYTES(FATFS_TOTAL_SECTORS))
#define FLASH_USER_SIZE                (200 * 1024)
#define FLASH_TOTAL_SECTORS            (BYTES_CONV_SECTORS(FLASH_USER_SIZE))

#define TOTAL_SECTORS                  (BYTES_CONV_SECTORS(FATFS_USED_SIZE + FLASH_USER_SIZE))

/* Readme.txt file data ---------------------------------------------------- */
#define README_FILE_LEN                301
static const unsigned char README_DATA[README_FILE_LEN] =
"kyChu FC Automatically-generated file. Do not edit!\r\n"
"Boot Version: V1.0.0\r\n"
"Flight Control Version: V1.0.0\r\n"
"Drone Serial Number: KY1801230001V1CN\r\n"
"\r\n""\r\n""\r\n"
"We choose to go to the moon in this decade and do the other things,\r\n"
"not because they are easy, but because they are hard.\r\n"
" -- John F. Kennedy, 1962";
/* Readme.txt file data ---------------------------------------------------- */

/* ---------- FATFS BOOT TABLE ---------- */
#define BOOT_TABLE_SIZE                SECTOR_SIZE         /* table size */
#define BOOT_TABLE_SECTOR_NUM          (1)                 /* number of sector used */
#define BOOT_TABLE_SECTOR_IDX          (0)                 /* sector offset */
#define BOOT_TABLE_OFFSET              (0)                 /* address offset */
#define BOOT_TABLE_USED_SIZE           (62)                /* number of bytes used */
static uint8_t BOOT_TABLE[62] = { /* MSWIN4.1 */
0xEB, 0x3C, 0x90,  'k',  'y',  'C',  'h',  'u',  '^',  '_',  '^', __LOBYTE(SECTOR_SIZE), __HIBYTE(SECTOR_SIZE), 0x01, 0x01, 0x00, 
0x02, 0x20, 0x00, __LOBYTE(TOTAL_SECTORS), __HIBYTE(TOTAL_SECTORS), 0xF0, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, RESERVED_BYTE, 0x29, 0x00, 0x00, 0x00, 0x00,  'k',  'y',  '.',  'C',  'h', 
 'u',  ' ',  'D',  'i',  's', 'k',  'F',  'A',  'T',  '1',  '2',  ' ',  ' ',  ' '
};

/* ---------- FATFS FATn TABLE ---------- */
#define FATn_TABLE_SIZE                (SECTOR_SIZE * 3)   /* table size */
#define FATn_TABLE_SECTOR_NUM          (3)                 /* number of sector used */
#define FAT1_TABLE_SECTOR_IDX          (1)                 /* sector offset */
#define FAT1_TABLE_OFFSET              ((uint32_t)0x200)   /* address offset */
#define FAT2_TABLE_SECTOR_IDX          (4)                 /* sector offset */
#define FAT2_TABLE_OFFSET              ((uint32_t)0x800)   /* address offset */
static uint8_t FATn_TABLE[FATn_TABLE_SIZE] = {0x00, 0x00, 0x00, 0x03, 0x40, 0x00, 0xFF, 0x0F};

/* ---------- FATFS ROOT TABLE ---------- */
#define ROOT_TABLE_SIZE                (SECTOR_SIZE * 2)   /* table size */
#define ROOT_TABLE_SECTOR_NUM          (2)                 /* number of sector used */
#define ROOT_TABLE_SECTOR_IDX          (7)                 /* sector offset */
#define ROOT_TABLE_OFFSET              ((uint32_t)0xE00)   /* address offset */
static uint8_t ROOT_TABLE[ROOT_TABLE_SIZE] = {
	/* TAB - 1 */
	 'k',  'y',  '.',  'C',  'h',  'u',  ' ',  'D',  'F',  'U',  ' ', FILE_ATTRIBUTES_VOL, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, 
	RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, __LOBYTE(FILE_TIME(22, 45, 32)), __HIBYTE(FILE_TIME(22, 45, 32)), __LOBYTE(FILE_DATE(1993, 8, 6)), __HIBYTE(FILE_DATE(1993, 8, 6)), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	/* TAB - 2 */
//	0xE5, 0xB0, 0x65, 0xFA, 0x5E, 0x87, 0x65, 0x2C, 0x67, 0x87, 0x65, FILE_ATTRIBUTES_LFN, 0x00, 0xD2, 0x63, 0x68, 
//	0x2E, 0x00, 0x74, 0x00, 0x78, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 
//0xE5, 0xC2, 0xBD, 0xA8, 0xCE, 0xC4, 0x7E, 0x31, 0x54, 0x58, 0x54, 0x20, 0x00, 0x00, 0xB0, 0xA6, 
//0x9B, 0x47, 0x9B, 0x47, 0x00, 0x00, 0xB1, 0xA6, 0x9B, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	/* TAB - 3 */
	 'R',  'E',  'A',  'D',  'M',  'E',  ' ',  ' ',  'T',  'X',  'T', FILE_ATTRIBUTES_RDO, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, 
	RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, RESERVED_BYTE, __LOBYTE(FILE_TIME(22, 45, 32)), __HIBYTE(FILE_TIME(22, 45, 32)), __LOBYTE(FILE_DATE(1993, 8, 6)), __HIBYTE(FILE_DATE(1993, 8, 6)), 0x02, 0x00,
	_FILE_SIZE_BYTE1_(README_FILE_LEN), _FILE_SIZE_BYTE2_(README_FILE_LEN), _FILE_SIZE_BYTE3_(README_FILE_LEN), _FILE_SIZE_BYTE4_(README_FILE_LEN),
};

/* ---------- README FILE DATA ---------- */
#define README_SECT_IDX                FATFS_TOTAL_SECTORS
#define README_SECT_NUM                (BYTES_CONV_SECTORS(README_FILE_LEN) + 1)

#define README_TAIL_LEN                (README_FILE_LEN - SECTORS_CONV_BYTES(BYTES_CONV_SECTORS(README_FILE_LEN)))

#endif /* __FAT_TAB_H */

/* ------------------------ (C) COPYRIGHT kyChu ----------- END OF FILE ----- */
