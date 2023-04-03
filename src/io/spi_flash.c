/*
 * File: spi_flash.c
 * Created Date: 2023-04-03 11:12:25 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 12:18:01 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "spi_flash.h"


volatile uint8_t spi_flash_status_idle() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_IDLE) & 1;
}

volatile uint8_t spi_flash_status_full_u8() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_FULL_U8) & 1;
}

volatile uint8_t spi_flash_status_full_u16() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_FULL_U16) & 1;
}

volatile uint8_t spi_flash_status_full_u32() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_FULL_U32) & 1;
}

volatile uint8_t spi_flash_status_av_u8() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_AV_U8) & 1;
}

volatile uint8_t spi_flash_status_av_u16() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_AV_U16) & 1;
}

volatile uint8_t spi_flash_status_av_u32() {
  MEM_ORDER
  return (SPI_FLASH->STATUS >> SPI_FLASH_STATUS_AV_U32) & 1;
}

void spi_flash_config(uint8_t en, uint8_t mode, uint8_t cmd_auto, uint8_t irq, uint32_t cycle) {
  SPI_FLASH->CONFIG = ((en & 0x1) << SPI_FLASH_CONFIG_EN) | ((mode & SPI_FLASH_MODE_MASK) << SPI_FLASH_CONFIG_MODE) | ((cmd_auto & 0x1) << SPI_FLASH_CONFIG_AUTO) | ((irq & SPI_FLASH_IRQ_MASK) << SPI_FLASH_CONFIG_IRQ);
  SPI_FLASH->CYCLE = cycle;
}

void spi_flash_req_u8(uint8_t rw, uint8_t mb, uint8_t data) {
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  if ((rw & SPI_FLASH_CMD_W) != 0) {
    *((volatile uint8_t *) SPI_FLASH->DATA) = data;
  }
}

void spi_flash_req_u16(uint8_t rw, uint8_t mb, uint16_t data) {
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  if ((rw & SPI_FLASH_CMD_W) != 0) {
    *((volatile uint16_t *) SPI_FLASH->DATA) = data;
  }
}

void spi_flash_req_u32(uint8_t rw, uint8_t mb, uint32_t data) {
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) SPI_FLASH->CMD) = (rw & SPI_FLASH_CMD_MASK) | ((mb & 0x01) << 7);
  if ((rw & SPI_FLASH_CMD_W) != 0) {
    *((volatile uint32_t *) SPI_FLASH->DATA) = data;
  }
}

void spi_flash_read_array(uint32_t addr, uint8_t *data, uint32_t size) {
  uint8_t nbyte = 0;

  SPI_FLASH->ADDR = addr;
  SPI_FLASH->OFFSET = size;
  *((volatile uint8_t *) SPI_FLASH->CMD) = SPI_FLASH_CMD_RA;

  while (nbyte < size) {
    if (spi_flash_status_av_u8() && (nbyte < size)) {
      data[nbyte] = spi_flash_read_u8(SPI_FLASH);
      nbyte = nbyte + 1;
    }
  }
}
