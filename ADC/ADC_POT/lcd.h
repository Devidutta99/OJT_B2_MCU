/*
 * lcd.h
 *
 *  Created on: Apr 22, 2023
 *      Author: PHY202302EF02
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

void print(unsigned char dat);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char mydat);
void lcd_init();
void lcd_display(char *str,unsigned int length);

#endif /* INC_LCD_H_ */
