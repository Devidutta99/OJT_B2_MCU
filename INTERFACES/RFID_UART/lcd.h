/*
 * lcd.h
 *
 *  Created on: Apr 20, 2023
 *      Author: PHY202302EF02
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
void LCD_init(void);
void PORTS_init(void);
void LCD_nibble_write(char data, unsigned char control);
void LCD_command(unsigned char command);
void LCD_data(char data);
void delay(int seconds);
void LCD_string(char str[]);


#endif /* INC_LCD_H_ */
