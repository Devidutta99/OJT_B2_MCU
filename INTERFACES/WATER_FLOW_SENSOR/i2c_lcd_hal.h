/*
 * i2c_lcd_hal.h
 *
 *  Created on: May 17, 2023
 *      Author: phytec
 */
#include"main.h"

#ifndef INC_I2C_LCD_HAL_H_
#define INC_I2C_LCD_HAL_H_

void lcd_write_nibble(uint8_t nibble, uint8_t rs);
void lcd_send_cmd(uint8_t cmd);
void lcd_send_data(uint8_t data);
void lcd_init();
void lcd_write_string(char *str);
void lcd_set_cursor(uint8_t row, uint8_t column);
void lcd_clear(void);
void lcd_backlight(uint8_t state);


#endif /* INC_I2C_LCD_HAL_H_ */
