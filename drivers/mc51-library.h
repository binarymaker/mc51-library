
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

#ifndef MC51_22e111f6_98bb_11e9_8b11_c8ff28b6c6d9
#define MC51_22e111f6_98bb_11e9_8b11_c8ff28b6c6d9

#include "mc51-library-cfg.h"

#include "REG52.h"
#include "stdint.h"
#include <intrins.h>

#include "gpio.h"

#define SET_BIT(REG, BIT) ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT) ((REG) & (BIT))
#define CLEAR_REG(REG) ((REG) = (0x0))
#define WRITE_REG(REG, VAL) ((REG) = (VAL))
#define READ_REG(REG) ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) WRITE_REG((REG), (((READ_REG(REG)) & \
                                                               (~(CLEARMASK))) | \
                                                              (SETMASK)))

typedef enum
{
  DISABLE = 0U,
  ENABLE
};

#define MACHINE_CYCLE (float)(FOSC / 12.00)


void _delay_us(uint32_t time_us);

void _delay_ms(uint32_t time_ms);

#endif // MC51_22e111f6_98bb_11e9_8b11_c8ff28b6c6d9
