
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
GPIO_ModePin(GPIO_Port port, uint8_t pin, GPIO_Mode mode)
{
  if (mode == GPIO_MODE_INPUT)
  {
    GPIO_WritePin(port, pin, GPIO_PIN_SET);
  }
  else
  {
    GPIO_WritePin(port, pin, GPIO_PIN_RESET);
  }
}

void 
GPIO_WritePin(GPIO_Port port, uint8_t pin, GPIO_PinState state)
{
  if (state == GPIO_PIN_RESET)
  {
    switch (port)
    {
    case GPIO_PORT_0:
      CLEAR_BIT(P0, pin);
      break;
    case GPIO_PORT_1:
      CLEAR_BIT(P1, pin);
      break;
    case GPIO_PORT_2:
      CLEAR_BIT(P2, pin);
      break;
    case GPIO_PORT_3:
      CLEAR_BIT(P3, pin);
      break;
    default:
      break;
    }
  }
  else
  {
    switch (port)
    {
    case GPIO_PORT_0:
      SET_BIT(P0, pin);
      break;
    case GPIO_PORT_1:
      SET_BIT(P1, pin);
      break;
    case GPIO_PORT_2:
      SET_BIT(P2, pin);
      break;
    case GPIO_PORT_3:
      SET_BIT(P3, pin);
      break;
    default:
      break;
    }
  }
}

void 
GPIO_TogglePin(GPIO_Port port, uint8_t pin)
{
  switch (port)
  {
  case GPIO_PORT_0:
    P0 = P0 ^ pin;
    break;
  case GPIO_PORT_1:
    P1 = P1 ^ pin;
    break;
  case GPIO_PORT_2:
    P2 = P2 ^ pin;
    break;
  case GPIO_PORT_3:
    P3 = P3 ^ pin;
    break;
  default:
    break;
  }
}

GPIO_PinState 
GPIO_ReadPin(GPIO_Port port, uint8_t pin)
{
  GPIO_PinState state;
    
  switch (port)
  {
  case GPIO_PORT_0:
    state = P0 & pin;
    break;
  case GPIO_PORT_1:
    state = P1 & pin;
    break;
  case GPIO_PORT_2:
    state = P2 & pin;
    break;
  case GPIO_PORT_3:
    state = P3 & pin;
    break;
  default:
    break;
  }
    
  if (state)
  {
    return 1;
  }
  
  return 0;
}
