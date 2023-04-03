/*
 * File: spi_flash.h
 * Created Date: 2023-04-03 11:12:25 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 11:21:26 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_SPI_FLASH_H 
#define IO_SPI_FLASH_H

#include <stdint.h>
#include "pltf.h"
#include "addr.h"
#include "../sys/isa.h"


// ******************************
//             MACRO
// ******************************
#define SPI_FLASH_ADDR_STATUS       0x000
#define SPI_FLASH_ADDR_CONFIG       0x004
#define SPI_FLASH_ADDR_CYCLE        0x008
#define SPI_FLASH_ADDR_ADDR         0x00c
#define SPI_FLASH_ADDR_OFFSET       0x010
#define SPI_FLASH_ADDR_CMD          0x020
#define SPI_FLASH_ADDR_DATA         0x028

#define SPI_FLASH_STATUS_IDLE       0
#define SPI_FLASH_STATUS_DMA        4
#define SPI_FLASH_STATUS_AUTO       5
#define SPI_FLASH_STATUS_FULL_U8    8 
#define SPI_FLASH_STATUS_FULL_U16   9 
#define SPI_FLASH_STATUS_FULL_U32   10 
#define SPI_FLASH_STATUS_FULL_U64   11 
#define SPI_FLASH_STATUS_AV_U8      16 
#define SPI_FLASH_STATUS_AV_U16     17
#define SPI_FLASH_STATUS_AV_U32     18
#define SPI_FLASH_STATUS_AV_U64     19

#define SPI_FLASH_CONFIG_EN         0
#define SPI_FLASH_CONFIG_MODE       3
#define SPI_FLASH_CONFIG_AUTO       16
#define SPI_FLASH_CONFIG_IRQ        24

#define SPI_FLASH_MODE_MASK         0x3
#define SPI_FLASH_MODE_BASE         0x0
#define SPI_FLASH_MODE_DUAL         0x1
#define SPI_FLASH_MODE_QUAD         0x2

#define SPI_FLASH_IRQ_MASK          0x3

#define SPI_FLASH_CMD_MASK          0x7
#define SPI_FLASH_CMD_NO            0x0
#define SPI_FLASH_CMD_R             0x1
#define SPI_FLASH_CMD_W             0x2
#define SPI_FLASH_CMD_RW            0x3
#define SPI_FLASH_CMD_RA            0x5

// ******************************
//           STRUCTURE
// ******************************
typedef struct {
  volatile uint32_t STATUS;
  volatile uint32_t CONFIG;
  volatile uint32_t CYCLE;
  volatile uint32_t ADDR;
  volatile uint32_t OFFSET;
  volatile uint32_t RESERVED0;
  volatile uint32_t RESERVED1;
  volatile uint32_t RESERVED2;
  volatile uint8_t CMD[8];
  volatile uint8_t DATA[8];
} SPI_FLASH_struct;

#define SPI_FLASH ((SPI_FLASH_struct *) (IO_PLTF_ADDR_SPI_FLASH_BASE))

// ******************************
//            FUNCTION
// ******************************
volatile uint8_t spi_flash_status_idle();
volatile uint8_t spi_flash_status_full_u8();
volatile uint8_t spi_flash_status_full_u16();
volatile uint8_t spi_flash_status_full_u32();
volatile uint8_t spi_flash_status_av_u8();
volatile uint8_t spi_flash_status_av_u16();
volatile uint8_t spi_flash_status_av_u32();
void spi_flash_config(uint8_t en, uint8_t mode, uint8_t cmd_auto, uint8_t irq, uint32_t cycle);

inline __attribute__ ((always_inline)) void spi_flash_write_cycle(uint32_t cycle) {
  SPI_FLASH->CYCLE = cycle;
}

inline __attribute__ ((always_inline)) void spi_flash_write_addr(uint32_t addr) {
  SPI_FLASH->ADDR = addr;
}

inline __attribute__ ((always_inline)) void spi_flash_write_offset(uint32_t offset) {
  SPI_FLASH->OFFSET = offset;
}

void spi_flash_req_u8(uint8_t rw, uint8_t mb, uint8_t data);
void spi_flash_req_u16(uint8_t rw, uint8_t mb, uint16_t data);
void spi_flash_req_u32(uint8_t rw, uint8_t mb, uint32_t data);

inline __attribute__ ((always_inline)) uint8_t spi_flash_read_u8() {
  return *((volatile uint8_t *) SPI_FLASH->DATA);
}

inline __attribute__ ((always_inline)) uint16_t spi_flash_read_u16() {
  return *((volatile uint16_t *) SPI_FLASH->DATA);
}

inline __attribute__ ((always_inline)) uint32_t spi_flash_read_u32() {
  return *((volatile uint32_t *) SPI_FLASH->DATA);
}

void spi_flash_read_mb(uint32_t addr, uint8_t *data, uint32_t size);

#endif
