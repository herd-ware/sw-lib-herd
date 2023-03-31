/*
 * File: isa.h
 * Created Date: 2023-03-31 02:17:43 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 02:24:35 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef SYS_ISA_H 
#define SYS_ISA_H

#include <stdint.h>
#include "pltf.h"


// ******************************
//            COMMON
// ******************************
#if (XLEN == 64)
  #define intx_t int64_t
  #define uintx_t uint64_t
#else
  #define intx_t int32_t
  #define uintx_t uint32_t
#endif

// ******************************
//            ASSEMBLY
// ******************************
#define MEM_ORDER \
asm volatile ( \
  "fence.tso" \
  ::: \
);

inline __attribute__ ((always_inline)) uintx_t read_cycle() {
  uintx_t cycle;
  asm volatile (
    "rdcycle %[r1]"
    : [r1] "=r" (cycle)     // output
    :                       // input
    :                       // registers
  );

  return cycle;
}

// ******************************
//            FUNCTION
// ******************************
void wait_ncycles(uintx_t ncycles);

#endif
