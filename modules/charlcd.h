
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

/* commands */
#define CHARLCD_CLEARDISPLAY        0x01
#define CHARLCD_RETURNHOME          0x02
#define CHARLCD_ENTRYMODESET        0x04
#define CHARLCD_DISPLAYCONTROL      0x08
#define CHARLCD_CURSORSHIFT         0x10
#define CHARLCD_FUNCTIONSET         0x20
#define CHARLCD_SETCGRAMADDR        0x40
#define CHARLCD_SETDDRAMADDR        0x80

/* flags for display entry mode */
#define CHARLCD_ENTRYRIGHT          0x00
#define CHARLCD_ENTRYLEFT           0x02
#define CHARLCD_ENTRYSHIFTRIGHT     0x01
#define CHARLCD_ENTRYSHIFTLEFT      0x00

/* flags for display on/off control */
#define CHARLCD_DISPLAYON           0x04
#define CHARLCD_DISPLAYOFF          0x00
#define CHARLCD_CURSORON            0x02
#define CHARLCD_CURSOROFF           0x00
#define CHARLCD_BLINKON             0x01
#define CHARLCD_BLINKOFF            0x00

/* flags for display/cursor shift */
#define CHARLCD_DISPLAYMOVE         0x08
#define CHARLCD_CURSORMOVE          0x00
#define CHARLCD_MOVERIGHT           0x04
#define CHARLCD_MOVELEFT            0x00

/* flags for function set */
#define CHARLCD_8BITMODE            0x10
#define CHARLCD_4BITMODE            0x00
#define CHARLCD_2LINE               0x08
#define CHARLCD_1LINE               0x00
#define CHARLCD_5x10DOTS            0x04
#define CHARLCD_5x8DOTS             0x00

typedef enum
{
  CHARLCD_CMD = 0U,
  CHARLCD_DATA
};

typedef struct
{
  GPIO_Pin_t regSelect_pin;
  GPIO_Pin_t enable_pin;
  GPIO_Pin_t data_pin[4];

  uint8_t reg_functionSet;
  uint8_t reg_displayControl;
  uint8_t reg_modeSet;
  
  uint8_t row_offset[4];
}CHARLCD_t;

void
CHARLCD_init(CHARLCD_t *context, uint8_t line, uint8_t col);

void
CHARLCD_Command(CHARLCD_t *context, uint8_t cmd);

void
CHARLCD_Data(CHARLCD_t *context, uint8_t cmd);

void
CHARLCD_Write(CHARLCD_t *context, uint8_t ch);

void
CHARLCD_SetCursor(CHARLCD_t *context, uint8_t line, uint8_t col);

void
CHARLCD_PrintString(CHARLCD_t *context, char *msg);

void
CHARLCD_PrintInteger(CHARLCD_t *context, uint8_t line, uint8_t col);
#endif // MC51_83e9ed30_9a17_11e9_b28f_c8ff28b6c6d9
