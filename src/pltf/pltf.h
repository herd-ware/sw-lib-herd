/*
 * File: pltf.h
 * Created Date: 2023-03-31 02:20:22 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-03-31 02:24:56 pm
 * Modified By: Mathieu Escouteloup
 * -----
 * License: See LICENSE.md
 * Copyright (c) 2023 HerdWare
 * -----
 * Description: 
 */


#ifndef PLTF_H 
#define PLTF_H

// ******************************
//         CONFIGURATION
// ******************************
// ------------------------------
//           CHAU1V000
// ------------------------------
#ifdef CONFIG_CHAU1V000
  #include "CHAU1V000.h"
// ------------------------------
//            DEFAULT
// ------------------------------
#else
  #include "default.h"
#endif

#endif
