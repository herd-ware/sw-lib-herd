/*
 * File: gpio.c
 * Created Date: 2023-03-31 05:10:01 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 05:24:17 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "gpio.h"


void gpio_set_bit(GPIO_struct *GPIO, uint8_t bit) {
  GPIO->ENO |= (1 << bit);
  GPIO->SET = (1 << bit);
}

void gpio_rst_bit(GPIO_struct *GPIO, uint8_t bit) {
  GPIO->ENO |= (1 << bit);
  GPIO->RST = (1 << bit);
}