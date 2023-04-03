/*
 * File: gpio.h
 * Created Date: 2023-03-31 05:09:11 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 05:24:09 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_GPIO_H 
#define IO_GPIO_H

#include <stdint.h>
#include "pltf.h"
#include "addr.h"
#include "../sys/isa.h"


// ******************************
//             MACRO
// ******************************

// ******************************
//           STRUCTURE
// ******************************
typedef struct {
  volatile uint32_t ENO;
  volatile uint32_t REG;
  volatile uint32_t SET;
  volatile uint32_t RST;
} GPIO_struct;

#define GPIOA ((GPIO_struct *) (IO_PLTF_ADDR_GPIOA_BASE))
#define GPIOB ((GPIO_struct *) (IO_PLTF_ADDR_GPIOB_BASE))
#define GPIOC ((GPIO_struct *) (IO_PLTF_ADDR_GPIOC_BASE))
#define GPIOD ((GPIO_struct *) (IO_PLTF_ADDR_GPIOD_BASE))

// ******************************
//            FUNCTION
// ******************************
void gpio_set_bit(GPIO_struct *GPIO, uint8_t bit);
void gpio_rst_bit(GPIO_struct *GPIO, uint8_t bit);

#endif
