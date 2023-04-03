/*
 * File: asm.h
 * Created Date: 2023-03-31 05:03:14 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 05:03:43 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef SYS_ASM_H 
#define SYS_ASM_H

#include "pltf.h"


// ******************************
//         DC REGISTERS
// ******************************
#define dc0   x0
#define dc1   x1
#define dc2   x2
#define dc3   x3
#define dc4   x4
#define dc5   x5
#define dc6   x6
#define dc7   x7
#define dc8   x8
#define dc9   x9
#define dc10  x10
#define dc11  x11
#define dc12  x12
#define dc13  x13
#define dc14  x14
#define dc15  x15
#define dc16  x16
#define dc17  x17
#define dc18  x18
#define dc19  x19
#define dc20  x20
#define dc21  x21
#define dc22  x22
#define dc23  x23
#define dc24  x24
#define dc25  x25
#define dc26  x26
#define dc27  x27
#define dc28  x28
#define dc29  x29
#define dc30  x30
#define dc31  x31
#define dc32  x32

// ******************************
//          LOAD/STORE
// ******************************
#if (XLEN == 64)
  #define lx ld
  #define sx sd
#else
  #define lx lw
  #define sx sw
#endif

#endif