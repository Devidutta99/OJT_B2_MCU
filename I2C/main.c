/*
Application: I2C
Problem statement: Interfacing of LCD with I2C protocol

Author: Devidutta Kabisatapathy 
*/
#include "LiquidCrystal_PCF8574.h"
#include "delay.h"
#include "stdio.h"
extern void SysClockConfig(void);

int main(void)
{
		//SysClockConfig();
		systick_init_ms(16000000);
		lcd_init();
		setCursor(5,0);
		lcd_send_string("I2C_LCD ");
		setCursor(2,1);
		lcd_send_string("INTERFACING");
		delay(2000);
		lcd_clear();
		while(1)
		{
			lcd_clear();
			setCursor(0,0);
			lcd_send_string("Welcome All to");
			setCursor(5,1);
			lcd_send_string("PHYTEC");
			delay(1000);
		}


}
