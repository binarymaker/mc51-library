
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
#include "charlcd.h"

void
CHARLCD_init(CHARLCD_t *context)
{
  uint8_t i;
  
  GPIO_ModePin(context->regSelect_pin.port,
               context->regSelect_pin.pin,
               GPIO_MODE_OUTPUT);
  
  GPIO_ModePin(context->enable_pin.port,
               context->enable_pin.pin,
               GPIO_MODE_OUTPUT);
  
  for (i = 0; i < 4; i++)
  {
    GPIO_ModePin(context->data_pin[i].port,
                 context->data_pin[i].pin,
                 GPIO_MODE_OUTPUT);
  }
}