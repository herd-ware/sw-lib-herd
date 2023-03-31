/*
 * File: isa.c
 * Created Date: 2023-03-31 02:17:43 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 02:17:56 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#include "isa.h"


void wait_ncycles(uintx_t ncycles) {
  uintx_t base = read_cycle();

  while (base + ncycles > read_cycle());
}