/*
 * File: pltf.h
 * Created Date: 2023-03-31 02:20:22 pm
 * Author: Mathieu Escouteloup
 * -----
 * Last Modified: 2023-04-03 11:04:52 am
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
//          P32CHAU1V000
// ------------------------------
#ifdef CONFIG_P32CHAU1V000
  #include "P32CHAU1V000.h"
// ------------------------------
//            DEFAULT
// ------------------------------
#else
  #include "default.h"
#endif

#endif
