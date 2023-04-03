/*
 * File: timer.h
 * Created Date: 2023-04-03 11:02:43 am
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 11:08:06 am
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef IO_TIMER_H 
#define IO_TIMER_H

#include <stdint.h>
#include "pltf.h"
#include "addr.h"
#include "../sys/isa.h"


// ******************************
//             MACRO
// ******************************
#define TIMER_CONFIG_EN     0

// ******************************
//           STRUCTURE
// ******************************
typedef struct {
  volatile uint32_t STATUS;
  volatile uint32_t CONFIG;
  volatile uint32_t CNT;
  volatile uint32_t CNTH;
  volatile uint32_t CMP;
  volatile uint32_t CMPH;
} TIMER_struct;

#if (ISA_NAME == CHAMP)
  #define L0TIMER ((TIMER_struct *) (IO_CORE_ADDR_L0TIMER_BASE))
  #define L1TIMER ((TIMER_struct *) (IO_CORE_ADDR_L1TIMER_BASE))
#else
  #define PTIMER0 ((TIMER_struct *) (IO_PLTF_ADDR_PTIMER0_BASE))
#endif

// ******************************
//            FUNCTION
// ******************************
#endif
