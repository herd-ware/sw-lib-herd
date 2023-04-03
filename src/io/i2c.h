/*
 * File: i2c.h
 * Created Date: 2023-04-03 11:12:25 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 11:20:27 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_I2C_H 
#define IO_I2C_H

#include <stdint.h>
#include "pltf.h"
#include "addr.h"
#include "../sys/isa.h"


// ******************************
//             MACRO
// ******************************
#define I2C_ADDR_STATUS       0x000
#define I2C_ADDR_CONFIG       0x004
#define I2C_ADDR_CYCLE        0x008
#define I2C_ADDR_ADDR         0x00c
#define I2C_ADDR_CMD          0x010
#define I2C_ADDR_DATA         0x018

#define I2C_STATUS_IDLE       0
#define I2C_STATUS_FULL_U8    8 
#define I2C_STATUS_FULL_U16   9 
#define I2C_STATUS_FULL_U32   10 
#define I2C_STATUS_FULL_U64   11 
#define I2C_STATUS_AV_U8      16 
#define I2C_STATUS_AV_U16     17
#define I2C_STATUS_AV_U32     18
#define I2C_STATUS_AV_U64     19

#define I2C_CONFIG_EN         0
#define I2C_CONFIG_IRQ        24

#define I2C_BAUD_100K         (CPU_FREQ / 100000)

// ******************************
//           STRUCTURE
// ******************************
typedef struct {
  volatile uint32_t STATUS;
  volatile uint32_t CONFIG;
  volatile uint32_t CYCLE;
  volatile uint32_t ADDR;
  volatile uint8_t CMD[8];
  volatile uint8_t DATA[8];
} I2C_struct;

#define I2C0 ((I2C_struct *) (IO_PLTF_ADDR_I2C0_BASE))

#define I2C_DEFAULT         I2C0
#define I2C_DEFAULT_BAUD    I2C_BAUD_9600

// ******************************
//            FUNCTION
// ******************************
volatile uint8_t i2c_status_idle(I2C_struct *I2C);
volatile uint8_t i2c_status_full_u8(I2C_struct *I2C);
volatile uint8_t i2c_status_full_u16(I2C_struct *I2C);
volatile uint8_t i2c_status_full_u32(I2C_struct *I2C);
volatile uint8_t i2c_status_av_u8(I2C_struct *I2C);
volatile uint8_t i2c_status_av_u16(I2C_struct *I2C);
volatile uint8_t i2c_status_av_u32(I2C_struct *I2C);

void i2c_config(I2C_struct *I2C, uint8_t en, uint8_t irq, uint32_t cycle, uint32_t addr);
inline __attribute__ ((always_inline)) void i2c_addr(I2C_struct *I2C, uint32_t addr) {
  I2C->ADDR = addr;
}

void i2c_req_u8(I2C_struct *I2C, uint8_t rw, uint8_t mb, uint8_t data);
void i2c_req_u16(I2C_struct *I2C, uint8_t rw, uint8_t mb, uint16_t data);
void i2c_req_u32(I2C_struct *I2C, uint8_t rw, uint8_t mb, uint32_t data);

inline __attribute__ ((always_inline)) uint8_t i2c_read_u8(I2C_struct *I2C) {
  return *((volatile uint8_t *) I2C->DATA);
}

inline __attribute__ ((always_inline)) uint16_t i2c_read_u16(I2C_struct *I2C) {
  return *((volatile uint16_t *) I2C->DATA);
}

inline __attribute__ ((always_inline)) uint32_t i2c_read_u32(I2C_struct *I2C) {
  return *((volatile uint32_t *) I2C->DATA);
}

void i2c_read_array(I2C_struct *I2C, uint8_t *data, uint8_t size);

#endif
