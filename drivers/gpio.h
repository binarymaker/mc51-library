
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

#ifndef MC51_1a3fd298_98bb_11e9_948e_c8ff28b6c6d9
#define MC51_1a3fd298_98bb_11e9_948e_c8ff28b6c6d9

#include "mc51-library.h"
#include "stdint.h"

typedef enum
{
  GPIO_PORT_0 = 0U,
  GPIO_PORT_1,
  GPIO_PORT_2,
  GPIO_PORT_3
} GPIO_Port;

#define GPIO_PIN_0   ((uint8_t)0x01U) /* Pin 0 selected    */
#define GPIO_PIN_1   ((uint8_t)0x02U) /* Pin 1 selected    */
#define GPIO_PIN_2   ((uint8_t)0x04U) /* Pin 2 selected    */
#define GPIO_PIN_3   ((uint8_t)0x08U) /* Pin 3 selected    */
#define GPIO_PIN_4   ((uint8_t)0x10U) /* Pin 4 selected    */
#define GPIO_PIN_5   ((uint8_t)0x20U) /* Pin 5 selected    */
#define GPIO_PIN_6   ((uint8_t)0x40U) /* Pin 6 selected    */
#define GPIO_PIN_7   ((uint8_t)0x80U) /* Pin 7 selected    */
#define GPIO_PIN_ALL ((uint8_t)0xFFU) /* All Pin selected  */

typedef enum
{
  GPIO_MODE_OUTPUT = 0U,
  GPIO_MODE_INPUT
} GPIO_Mode;

typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
} GPIO_PinState;

void
GPIO_PinMode(GPIO_Port port, uint8_t pin, GPIO_Mode mode);

void 
GPIO_WritePin(GPIO_Port port, uint8_t pin, GPIO_PinState state);

void 
GPIO_TogglePin(GPIO_Port port, uint8_t pin);

GPIO_PinState 
GPIO_ReadPin(GPIO_Port port, uint8_t pin);

#endif // MC51_1a3fd298_98bb_11e9_948e_c8ff28b6c6d9
