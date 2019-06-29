
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
CHARLCD_init(CHARLCD_t *context, uint8_t line, uint8_t col)
{
  uint8_t i;
  
  context->row_offset[0] = 0x00;
  context->row_offset[1] = 0x40;
  context->row_offset[3] = col;
  context->row_offset[4] = 0x40 + col;
  
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

  /* Init sequnce as per datasheet */
  _delay_ms(100);                   /* 100ms wait for display stable */
  CHARLCD_Write(context, 0x03);
  _delay_ms(5);                     /* 4.1ms wait */
  CHARLCD_Write(context, 0x03);
  _delay_us(100);                   /* 100us wait */
  CHARLCD_Write(context, 0x03);
  _delay_us(100);                   /* 100us wait */
  CHARLCD_Write(context, 0x02);
  
  /* Function set config ------------------------------------------------- */
  context->reg_functionSet = CHARLCD_FUNCTIONSET | CHARLCD_4BITMODE |
                             CHARLCD_5x8DOTS;
  
  if (line > 0x01)
  {
    context->reg_functionSet |= CHARLCD_2LINE;
  }
  else
  {
    context->reg_functionSet |= CHARLCD_1LINE;
  }
  
  CHARLCD_Command(context, context->reg_functionSet);
  
  /* Display control config ----------------------------------------------- */
  
  context->reg_displayControl = CHARLCD_DISPLAYCONTROL | CHARLCD_DISPLAYON |
                                CHARLCD_CURSOROFF | CHARLCD_BLINKOFF;
  
  CHARLCD_Command(context, context->reg_displayControl);

  /* Clear display -------------------------------------------------------- */
  CHARLCD_Command(context, CHARLCD_CLEARDISPLAY);
  _delay_ms(10);
  
  /* Entry mode / cursor increment config --------------------------------- */
  context->reg_modeSet = CHARLCD_ENTRYMODESET | CHARLCD_ENTRYLEFT | 
                          CHARLCD_ENTRYSHIFTLEFT;
  
  CHARLCD_Command(context, context->reg_modeSet);
}

void
CHARLCD_EnablePulse(CHARLCD_t *context)
{
  GPIO_WritePin(context->enable_pin.port,
                context->enable_pin.pin,
                GPIO_PIN_SET);
  
  _delay_us(100);

  GPIO_WritePin(context->enable_pin.port,
                context->enable_pin.pin,
                GPIO_PIN_RESET);
}

void
CHARLCD_Write(CHARLCD_t *context, uint8_t ch)
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    GPIO_WritePin(context->data_pin[i].port,
                  context->data_pin[i].pin,
                  (ch >> i) & 0x01);
  }
  
  CHARLCD_EnablePulse(context);
}

void
CHARLCD_Command(CHARLCD_t *context, uint8_t cmd)
{
  uint8_t msb;
  uint8_t lsb;
  
  GPIO_WritePin(context->regSelect_pin.port,
                context->regSelect_pin.pin,
                GPIO_PIN_RESET);

  msb = (cmd >> 4) & 0x0F;
  lsb = cmd  & 0x0F;
  
  CHARLCD_Write(context, msb);
  CHARLCD_Write(context, lsb);
}

void
CHARLCD_Data(CHARLCD_t *context, uint8_t cmd)
{
  uint8_t msb;
  uint8_t lsb;
  
  GPIO_WritePin(context->regSelect_pin.port,
                context->regSelect_pin.pin,
                GPIO_PIN_SET);

  msb = (cmd >> 4) & 0x0F;
  lsb = cmd  & 0x0F;
  
  CHARLCD_Write(context, msb);
  CHARLCD_Write(context, lsb);
}

void
CHARLCD_SetCursor(CHARLCD_t *context, uint8_t line, uint8_t col){
  CHARLCD_Command(context , CHARLCD_SETDDRAMADDR | (context->row_offset[line] + col));
}

void
CHARLCD_PrintString(CHARLCD_t *context, char *msg)
{
  uint16_t i = 0;
  
  while (msg[i] != '\0')
  {
    CHARLCD_Data(context, (uint8_t)msg[i]);
    i++;
  }
}

void
CHARLCD_PrintInteger(CHARLCD_t *context, uint8_t line, uint8_t col)
{
  _delay_ms(1);
}