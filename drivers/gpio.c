
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

#include "gpio.h"

void 
GPIO_WritePin(GPIO_Port port, uint8_t pin)
{
  switch (port)
  {
  case GPIO_PORT_0:
    WRITE_REG(P0, pin);
    break;
  case GPIO_PORT_1:
    WRITE_REG(P1, pin);
    break;
  case GPIO_PORT_2:
    WRITE_REG(P2, pin);
    break;
  case GPIO_PORT_3:
    WRITE_REG(P3, pin);
    break;
  default:
    break;
  }
}