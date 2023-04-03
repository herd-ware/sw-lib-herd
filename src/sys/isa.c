/*
 * File: isa.c
 * Created Date: 2023-03-31 02:17:43 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 10:15:02 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "isa.h"


void wait_cycle(uintx_t cycle) {
  uintx_t base = read_cycle();

  while (base + cycle > read_cycle());
}