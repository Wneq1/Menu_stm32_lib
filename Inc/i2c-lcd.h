#ifndef I2C_LCD_H
#define I2C_LCD_H

#include "stm32l1xx_hal.h"

extern I2C_HandleTypeDef hi2c1;  // Change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4E  // Change this according to your setup

#define LCD_COLS 16  // Przykładowa liczba kolumn
#define LCD_ROWS 2
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_clear(void);
void lcd_put_cur(int row, int col);
void lcd_init(void);
void lcd_send_string(char *str);

#endif // I2C_LCD_H
