/*
 * File: uart.c
 * Created Date: 2023-03-31 05:30:03 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 10:35:06 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "uart.h"


void uart_config(UART_struct *UART, uint8_t en, uint8_t is8bit, uint8_t parity, uint8_t stop, uint8_t irq, uint32_t cycle) {
  UART->CONFIG = ((en & 0x1) << UART_CONFIG_EN) | ((is8bit & 0x1) << UART_CONFIG_8BIT) | ((parity & 0x1) << UART_CONFIG_PARITY) | ((stop & 0x3) << UART_CONFIG_STOP) | ((irq & 0x3) << UART_CONFIG_IRQ);
  UART->CYCLE = cycle;
}

volatile uint8_t uart_status_idle(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_IDLE) & 1;
}

volatile uint8_t uart_status_full_u8(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_FULL_U8) & 1;
}

volatile uint8_t uart_status_full_u16(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_FULL_U16) & 1;
}

volatile uint8_t uart_status_full_u32(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_FULL_U32) & 1;
}

volatile uint8_t uart_status_av_u8(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_AV_U8) & 1;
}

volatile uint8_t uart_status_av_u16(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_AV_U16) & 1;
}

volatile uint8_t uart_status_av_u32(UART_struct *UART) {
  MEM_ORDER
  return (UART->STATUS >> UART_STATUS_AV_U32) & 1;
}

void uart_send_array(UART_struct *UART, uint8_t *data, uint32_t size) {
  uint32_t index;

  while (index < size) {
    if (!uart_status_full_u8(UART)) {
      uart_send_u8(UART, data[index]);
      index = index + 1;
    }
  }
}

void uart_rec_array(UART_struct *UART, uint8_t *data, uint32_t size) {
  uint32_t index;

  while (index < size) {
    if (uart_status_av_u8(UART)) {
      data[index] = uart_rec_u8(UART);
      index = index + 1;
    }
  }
}
