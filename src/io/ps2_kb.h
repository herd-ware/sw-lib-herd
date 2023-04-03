/*
 * File: ps2_kb.h
 * Created Date: 2023-04-03 10:37:33 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 10:49:43 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_PS2_KB_H 
#define IO_PS2_KB_H

#include <stdint.h>
#include "pltf.h"
#include "addr.h"
#include "../sys/isa.h"


// ******************************
//             MACRO
// ******************************
#define PS2_KB_ADDR_STATUS      0x000
#define PS2_KB_ADDR_CONFIG      0x004
#define PS2_KB_ADDR_CYCLE       0x008
#define PS2_KB_ADDR_DATA        0x010

#define PS2_KB_STATUS_IDLE      0
#define PS2_KB_STATUS_FULL_U8   8 
#define PS2_KB_STATUS_FULL_U16  9 
#define PS2_KB_STATUS_FULL_U32  10 
#define PS2_KB_STATUS_FULL_U64  11 
#define PS2_KB_STATUS_AV_U8     16 
#define PS2_KB_STATUS_AV_U16    17
#define PS2_KB_STATUS_AV_U32    18
#define PS2_KB_STATUS_AV_U64    19

#define PS2_KB_CONFIG_EN        0
#define PS2_KB_CONFIG_IRQ       24

#define LAYOUT_QWERTY           0
#define LAYOUT_AZERTY           1

// ******************************
//           STRUCTURE
// ******************************
typedef struct {
  volatile uint32_t STATUS;
  volatile uint32_t CONFIG;
  volatile uint32_t CYCLE;
  volatile uint32_t RESERVED0;
  volatile uint8_t DATA[8];
} PS2_KB_struct;

#define PS2_KB ((PS2_KB_struct *) (IO_PLTF_ADDR_PS2_KB_BASE))

// ******************************
//            FUNCTION
// ******************************
volatile uint8_t ps2_kb_status_idle();
volatile uint8_t ps2_kb_status_full_u8();
volatile uint8_t ps2_kb_status_full_u16();
volatile uint8_t ps2_kb_status_full_u32();
volatile uint8_t ps2_kb_status_av_u8();
volatile uint8_t ps2_kb_status_av_u16();
volatile uint8_t ps2_kb_status_av_u32();
void ps2_kb_config(uint8_t en, uint8_t irq, uint8_t new_layout, uint32_t cycle);

inline __attribute__ ((always_inline)) void ps2_kb_send_u8(uint8_t data) {
  *((volatile uint8_t *) PS2_KB->DATA) = data;
}

inline __attribute__ ((always_inline)) void ps2_kb_send_u16(uint16_t data) {
  *((volatile uint16_t *) PS2_KB->DATA) = data;
}

inline __attribute__ ((always_inline)) void ps2_kb_send_u32(uint32_t data) {
  *((volatile uint32_t *) PS2_KB->DATA) = data;
}

inline __attribute__ ((always_inline)) uint8_t ps2_kb_read_u8() {
  return *((volatile uint8_t *) PS2_KB->DATA);
}

inline __attribute__ ((always_inline)) uint16_t ps2_kb_read_u16() {
  return *((volatile uint16_t *) PS2_KB->DATA);
}

inline __attribute__ ((always_inline)) uint32_t ps2_kb_read_u32() {
  return *((volatile uint32_t *) PS2_KB->DATA);
}

uint8_t ps2_kb_convert(uint8_t scan);

#endif
