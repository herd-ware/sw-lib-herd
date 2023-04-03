/*
 * File: default.h
 * Created Date: 2023-03-31 02:19:56 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 11:07:48 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef PLTF_DEFAULT_H 
#define PLTF_DEFAULT_H


// ******************************
//            DEFAULT
// ******************************
#define CPU_FREQ          1000000
#define XLEN              32
#define ISA_NAME          PRIV

#define IO_CORE_ADDR_BASE 0x10000000
#define IO_PLTF_ADDR_BASE 0x18000000

#define CPU_N_UART        1
#define CPU_N_SCRATCH     8

#endif
