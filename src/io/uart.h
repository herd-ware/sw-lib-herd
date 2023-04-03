/*
 * File: uart.h
 * Created Date: 2023-03-31 05:25:47 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 12:18:55 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_UART_H 
#define IO_UART_H

#include <stdint.h>
#include "pltf.h"
#include "addr.h"
#include "../sys/isa.h"


// ******************************
//             MACRO
// ******************************
#define UART_ADDR_STATUS      0x000
#define UART_ADDR_CONFIG      0x004
#define UART_ADDR_CYCLE       0x008
#define UART_ADDR_DATA        0x010

#define UART_STATUS_IDLE      0
#define UART_STATUS_FULL_U8   8 
#define UART_STATUS_FULL_U16  9 
#define UART_STATUS_FULL_U32  10 
#define UART_STATUS_FULL_U64  11 
#define UART_STATUS_AV_U8     16 
#define UART_STATUS_AV_U16    17
#define UART_STATUS_AV_U32    18
#define UART_STATUS_AV_U64    19

#define UART_CONFIG_EN        0
#define UART_CONFIG_8BIT      1
#define UART_CONFIG_PARITY    2
#define UART_CONFIG_STOP      3
#define UART_CONFIG_IRQ       24

#define UART_BAUD_9600        (CPU_FREQ / 9600)
#define UART_BAUD_115200      (CPU_FREQ / 115200)
#define UART_BAUD_230400      (CPU_FREQ / 230400)

#define UART_WAIT_IDLE_(uart) while (!(uart->STATUS & (1 << UART_STATUS_IDLE)));
#define UART_WAIT_IDLE(uart)  UART_WAIT_IDLE_(uart)

// ******************************
//           STRUCTURE
// ******************************
typedef struct {
  volatile uint32_t STATUS;
  volatile uint32_t CONFIG;
  volatile uint32_t CYCLE;
  volatile uint32_t RESERVED0;
  volatile uint8_t DATA[XLEN >> 3];
} UART_struct;

#define UART0 ((UART_struct *) (IO_PLTF_ADDR_UART0_BASE))

#define UART_DEFAULT        UART0
#define UART_DEFAULT_BAUD   UART_BAUD_9600

// ******************************
//            FUNCTION
// ******************************
volatile uint8_t uart_status_idle(UART_struct *UART);
volatile uint8_t uart_status_full_u8(UART_struct *UART);
volatile uint8_t uart_status_full_u16(UART_struct *UART);
volatile uint8_t uart_status_full_u32(UART_struct *UART);
volatile uint8_t uart_status_av_u8(UART_struct *UART);
volatile uint8_t uart_status_av_u16(UART_struct *UART);
volatile uint8_t uart_status_av_u32(UART_struct *UART);

void uart_config(UART_struct *UART, uint8_t en, uint8_t is8bit, uint8_t parity, uint8_t stop, uint8_t irq, uint32_t cycle);

inline __attribute__ ((always_inline)) void uart_send_u8(UART_struct *UART, uint8_t data) {
  *((volatile uint8_t *) UART->DATA) = data;
}

inline __attribute__ ((always_inline)) void uart_send_u16(UART_struct *UART, uint16_t data) {
  *((uint16_t *) UART->DATA) = data;
}

inline __attribute__ ((always_inline)) void uart_send_u32(UART_struct *UART, uint32_t data) {
  *((uint32_t *) UART->DATA) = data;
}

void uart_send_array(UART_struct *UART, uint8_t *data, uint32_t size);

inline __attribute__ ((always_inline)) uint8_t uart_rec_u8(UART_struct *UART) {
  return *((uint8_t *) UART->DATA);
}

inline __attribute__ ((always_inline)) uint16_t uart_rec_u16(UART_struct *UART) {
  return *((uint16_t *) UART->DATA);
}

inline __attribute__ ((always_inline)) uint32_t uart_rec_u32(UART_struct *UART) {
  return *((uint32_t *) UART->DATA);
}

void uart_rec_array(UART_struct *UART, uint8_t *data, uint32_t size);

#endif
