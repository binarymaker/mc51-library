
/**
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  */

#ifndef MC51_83e9ed30_9a17_11e9_b28f_c8ff28b6c6d9
#define MC51_83e9ed30_9a17_11e9_b28f_c8ff28b6c6d9

#include "mc51-library.h"

typedef enum
{
  CHARLCD_TYPE_16X1 = 0U,
  CHARLCD_TYPE_16X2,
  CHARLCD_TYPE_16X4
}CHARLCD_Type;

typedef struct
{
  CHARLCD_Type size_type;
  GPIO_Pin_t regSelect_pin;
  GPIO_Pin_t enable_pin;
  GPIO_Pin_t data_pin[4];
}CHARLCD_t;

void
CHARLCD_init(CHARLCD_t *context);


#endif // MC51_83e9ed30_9a17_11e9_b28f_c8ff28b6c6d9
