/*
 Application: GPIO Code
 Step1: SET PORTC
 Step2: SET THE MODER TO OUTPUT
 Step3: SET THE PIN TO 6
Author: Devidutta Kabisatapathy*/



#include"main.h"

int main(){
	RCC->AHB1ENR |= 0x4;
	GPIOC->MODER |= 0x1000;
	while(1){
	GPIOC->ODR |=0X40;
	delay(1000);
	GPIOC->ODR &=~(0X40);
	delay(1000);
	}
}
void delay(int seconds){
	unsigned long int count=4000,i,j;

	for(i=0;i<seconds;i++){
	    for(j=0;j<count;j++);}
}
