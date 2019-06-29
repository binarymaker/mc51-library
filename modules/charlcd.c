
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

  CHARLCD_Command(context, 0x03);
  _delay_ms(50);
  CHARLCD_Command(context, 0x03);
  _delay_ms(110);
  CHARLCD_Command(context, 0x03);
  CHARLCD_Command(context, 0x02);
  CHARLCD_Command(context, 0x02);
  CHARLCD_Command(context, 0x08);
  CHARLCD_Command(context, 0x00);
  CHARLCD_Command(context, 0x0C);
  CHARLCD_Command(context, 0x00);
  CHARLCD_Command(context, 0x06);
  CHARLCD_Command(context, 0x01);
  _delay_ms(100);
  
  CHARLCD_Command(context, 0x80);
  CHARLCD_Data(context, 'A');
}

void
CHARLCD_EnablePulse(CHARLCD_t *context)
{
  GPIO_WritePin(context->enable_pin.port,
                context->enable_pin.pin,
                GPIO_PIN_SET);
  
  _delay_ms(5);

  GPIO_WritePin(context->enable_pin.port,
                context->enable_pin.pin,
                GPIO_PIN_RESET);
}

void
CHARLCD_Write(CHARLCD_t *context, uint8_t ch)
{
  uint8_t i;
  uint8_t lsb;
  uint8_t msb;
  
  lsb = ch & 0x0F;
  msb = (ch >> 4) & 0x0F;

  /* MSB 4bit send */
  for (i = 0; i < 4; i++)
  {
    GPIO_WritePin(context->data_pin[i].port,
                  context->data_pin[i].pin,
                  (msb >> i) & 0x01);
  }
  
  CHARLCD_EnablePulse(context);

  /* LSB 4bit send */
  for (i = 0; i < 4; i++)
  {
    GPIO_WritePin(context->data_pin[i].port,
                  context->data_pin[i].pin,
                  (lsb >> i) & 0x01);
  }
  
  CHARLCD_EnablePulse(context);

}

void
CHARLCD_Command(CHARLCD_t *context, uint8_t cmd)
{
  GPIO_WritePin(context->regSelect_pin.port,
                context->regSelect_pin.pin,
                GPIO_PIN_RESET);

  CHARLCD_Write(context, cmd);
}

void
CHARLCD_Data(CHARLCD_t *context, uint8_t cmd)
{
  GPIO_WritePin(context->regSelect_pin.port,
                context->regSelect_pin.pin,
                GPIO_PIN_SET);

  CHARLCD_Write(context, cmd);
}