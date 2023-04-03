/*
 * File: ps2_kb.c
 * Created Date: 2023-04-03 10:37:33 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 10:49:54 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "ps2_kb.h"

uint8_t layout;

const uint8_t ps2_kb_scan2ascii_qwerty[] = {
  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    '\t', '`',  0,
  0,    0,    0,    0,    0,    'Q',  '1',  0,    0,    0,    'Z',  'S',  'A',  'W',  '2',  0,
  0,    'C',  'X',  'D',  'E',  '4',  '3',  0,    0,    0,    'V',  'F',  'T',  'R',  '5',  0,
  0,    'N',  'B',  'H',  'G',  'Y',  '6',  0,    0,    0,    'M',  'J',  'U',  '7',  '8',  0,
  0,    ',',  'K',  'I',  'O',  '0',  '9',  0,    0,    '.',  '/',  'L',  'C',  'P',  '-',  0,
  0,    0,    '\'', 0,    '[',  '=',  0,    0,    0,    0,    0,    ']',  0,    '\\', 0,    0,
  0,    0,    0,    0,    0,    0,    0,    0,    0,    '1',  0,    '4',  '7',  0,    0,    0,
  '0',  '.',  '2',  '5',  '6',  '8',  0,    0,    0,    '+',  '3',  '-',  '*',  '9',  0,    0,
};

const uint8_t ps2_kb_scan2ascii_azerty[] = {
  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    '\t', '`',  0,
  0,    0,    0,    0,    0,    'A',  '1',  0,    0,    0,    'W',  'S',  'Q',  'Z',  '2',  0,
  0,    'C',  'X',  'D',  'E',  '4',  '3',  0,    0,    0,    'V',  'F',  'T',  'R',  '5',  0,
  0,    'N',  'B',  'H',  'G',  'Y',  '6',  0,    0,    0,    ',',  'J',  'U',  '7',  '8',  0,
  0,    ';',  'K',  'I',  'O',  '0',  '9',  0,    0,    ':',  '!',  'L',  'M',  'P',  '-',  0,
  0,    0,    0,    0,    '^',  '=',  0,    0,    0,    0,    0,    '$',  0,    '*',  0,    0,
  0,    0,    0,    0,    0,    0,    0,    0,    0,    '1',  0,    '4',  '7',  0,    0,    0,
  '0',  '.',  '2',  '5',  '6',  '8',  0,    0,    0,    '+',  '3',  '-',  '*',  '9',  0,    0,
};

volatile uint8_t ps2_kb_status_idle() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_IDLE) & 1;
}

volatile uint8_t ps2_kb_status_full_u8() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_FULL_U8) & 1;
}

volatile uint8_t ps2_kb_status_full_u16() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_FULL_U16) & 1;
}

volatile uint8_t ps2_kb_status_full_u32() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_FULL_U32) & 1;
}

volatile uint8_t ps2_kb_status_av_u8() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_AV_U8) & 1;
}

volatile uint8_t ps2_kb_status_av_u16() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_AV_U16) & 1;
}

volatile uint8_t ps2_kb_status_av_u32() {
  MEM_ORDER
  return (PS2_KB->STATUS >> PS2_KB_STATUS_AV_U32) & 1;
}

void ps2_kb_config(uint8_t en, uint8_t irq, uint8_t new_layout, uint32_t cycle) {
  PS2_KB->CONFIG = ((en & 0x1) << PS2_KB_CONFIG_EN) | ((irq & 0x3) << PS2_KB_CONFIG_IRQ);
  PS2_KB->CYCLE = cycle;
  layout = new_layout;
}

uint8_t ps2_kb_convert(uint8_t scan) {  
  uint8_t conv;

  if (scan > 0x7f) {
    return 0;
  } else {
    switch (layout) {
      case (LAYOUT_QWERTY):
        conv = ps2_kb_scan2ascii_qwerty[scan];
        break;
      case (LAYOUT_AZERTY):
        conv = ps2_kb_scan2ascii_azerty[scan];
        break;
      default:
        conv = ps2_kb_scan2ascii_qwerty[scan];
        break;
    }    
  }  

  return conv;
}
