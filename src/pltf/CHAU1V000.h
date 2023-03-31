/*
 * File: CHAU1V000.h
 * Created Date: 2023-03-31 02:18:48 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 02:25:08 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef PLTF_CHAU1V000_H 
#define PLTF_CHAU1V000_H


// ******************************
//           CHAU1V000
// ******************************
#ifdef CONFIG_CHAU1V000
  #define CPU_FREQ        50000000
#else
  #define CPU_FREQ        1000000
#endif
#define XLEN              32

#define IO_CORE_ADDR_BASE 0x10000000
#define IO_PLTF_ADDR_BASE 0x18000000

#define CPU_N_UART        1
#define CPU_N_SCRATCH     8

#endif
