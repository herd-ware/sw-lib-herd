/*
 * File: P32CHAU1V000.h
 * Created Date: 2023-03-31 02:18:48 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-22 08:19:55 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef PLTF_P32CHAU1V000_H 
#define PLTF_P32CHAU1V000_H


// ******************************
//          P32CHAU1V000
// ******************************
#if (IS_SIM > 0)
  #define CPU_FREQ        1152000  
#else
  #define CPU_FREQ        50000000
#endif
#define XLEN              32
#define ISA_NAME          PRIV

#define IO_CORE_ADDR_BASE 0x10000000
#define IO_PLTF_ADDR_BASE 0x18000000

#define CPU_N_UART        1
#define CPU_N_SCRATCH     8

#endif
