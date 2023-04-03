/*
 * File: i2c.c
 * Created Date: 2023-04-03 11:12:25 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 11:20:41 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "i2c.h"


volatile uint8_t i2c_status_idle(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_IDLE) & 1;
}

volatile uint8_t i2c_status_full_u8(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_FULL_U8) & 1;
}

volatile uint8_t i2c_status_full_u16(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_FULL_U16) & 1;
}

volatile uint8_t i2c_status_full_u32(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_FULL_U32) & 1;
}

volatile uint8_t i2c_status_av_u8(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_AV_U8) & 1;
}

volatile uint8_t i2c_status_av_u16(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_AV_U16) & 1;
}

volatile uint8_t i2c_status_av_u32(I2C_struct *I2C) {
  MEM_ORDER
  return (I2C->STATUS >> I2C_STATUS_AV_U32) & 1;
}

void i2c_config(I2C_struct *I2C, uint8_t en, uint8_t irq, uint32_t cycle, uint32_t addr) {
  I2C->CONFIG = ((en & 0x1) << I2C_CONFIG_EN) | ((irq & 0x3) << I2C_CONFIG_IRQ);
  I2C->CYCLE = cycle;
  I2C->ADDR = addr;
}

void i2c_req_u8(I2C_struct *I2C, uint8_t rw, uint8_t mb, uint8_t data) {
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  if ((rw & 0x01) == 1) {
    *((volatile uint8_t *) I2C->DATA) = data;
  }
}

void i2c_req_u16(I2C_struct *I2C, uint8_t rw, uint8_t mb, uint16_t data) {
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  if ((rw & 0x01) == 1) {
    *((volatile uint16_t *) I2C->DATA) = data;
  }
}

void i2c_req_u32(I2C_struct *I2C, uint8_t rw, uint8_t mb, uint32_t data) {
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  *((volatile uint8_t *) I2C->CMD) = (rw & 0x01) | ((mb & 0x01) << 7);
  if ((rw & 0x01) == 1) {
    *((volatile uint32_t *) I2C->DATA) = data;
  }
}

void i2c_read_array(I2C_struct *I2C, uint8_t *data, uint8_t size) {
  uint8_t nreq = 0;
  uint8_t nread = 0;

  *((volatile uint8_t *) I2C->CMD) = 0x00;
  nreq = 1;

  while ((nreq < size) || (nread < size)) {
    if (!i2c_status_full_u8(I2C) && (nreq < size)) {
      *((volatile uint8_t *) I2C->CMD)= (0x01 << 7);
      nreq = nreq + 1;
    }

    if (i2c_status_av_u8(I2C) && (nread < size)) {
      data[nread] = i2c_read_u8(I2C);
      nread = nread + 1;
    }
  }
}
