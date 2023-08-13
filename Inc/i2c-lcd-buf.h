#ifndef LCD_BUF_I2C_H
#define LCD_BUF_I2C_H

#include "i2c-lcd.h"  // Include your I2C LCD library header file
#include "stdlib.h"

#define LCD_ROWS 2
#define LCD_COLS 16

extern char lcd_buf[LCD_ROWS][LCD_COLS];
extern char lcd_buf_old[LCD_ROWS][LCD_COLS];
extern uint8_t lcd_buf_x, lcd_buf_y;

void buf_locate(uint8_t x, uint8_t y);
void buf_char(char c);
void buf_clear(void);
void lcd_refresh(void);
void buf_str(char *text);
void buf_str_XY(uint8_t x, uint8_t y, char *text);

#endif // LCD_BUF_I2C_H

