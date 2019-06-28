
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

#include "mc51-library.h"
#include "mc51-library-cfg.h"

void _delay_us(uint32_t time_us)
{
  uint32_t wait_time;
  
  wait_time = time_us / 120;
  while(wait_time--)
  {
    _nop_();
  }
}

void _delay_ms(uint32_t time_ms)
{
  uint32_t wait_time;
  
  wait_time = MACHINE_CYCLE * time_ms;
  while(wait_time--)
  {
    _delay_us(1000);
  }
}


