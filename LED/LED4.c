/*Application: LED Interface
Problem Statement: Display 0 to 9 using register code.

Author:Devidutta Kabisatapathy*/
#include "main.h"
void delay(int seconds){
	unsigned long int count=4000,i,j;

	for(i=0;i<seconds;i++){
	    for(j=0;j<count;j++);}
}
int main(){
	RCC->AHB1ENR = 0X4;
	GPIOC->MODER= 0X1555;

	//FOR 0
	GPIOC->ODR = ~(0x3F);
	delay(100);
	//FOR 1
	GPIOC->ODR = ~(0x6);
	delay(100);
	//FOR 2
	GPIOC->ODR = ~(0x5B);
	delay(100);
	//FOR 3
	GPIOC->ODR = ~(0x4F);
	delay(100);
	//FOR 4
	GPIOC->ODR = ~(0x66);
	delay(100);
	//FOR 5
	GPIOC->ODR = ~(0X3F);
	delay(100);
	//FOR 6
	GPIOC->ODR = ~(0x7D);
	delay(100);
	//FOR 7
	GPIOC->ODR = ~(0x7);
	delay(100);
	//FOR 8
	GPIOC->ODR = ~(0x7F);
	delay(100);
	//FOR 9
	GPIOC->ODR = ~(0x67);
	delay(100);
}
