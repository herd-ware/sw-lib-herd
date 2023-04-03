/*
 * File: scratch.h
 * Created Date: 2023-03-31 06:06:34 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 06:07:11 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_SCRATCH_H 
#define IO_SCRATCH_H

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
  volatile uint32_t REG[CPU_N_SCRATCH];
} SCRATCH_struct;

#define SCRATCH ((SCRATCH_struct *) (IO_CORE_ADDR_SCRATCH_BASE))

// ******************************
//            FUNCTION
// ******************************
#endif
