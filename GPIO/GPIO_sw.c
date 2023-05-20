/*
 Application: GPIO Code
 Step1: SET PORTA
 Step2: SET THE MODER TO OUTPUT
 Step3: SET THE PIN TO 5

 Author: Devidutta Kabisatapathy*/

#include"main.h"

#if(0)
//using GPIOx_IDR
void delay(int seconds){
	unsigned long int count=4000,i,j;

	for(i=0;i<seconds;i++){
	    for(j=0;j<count;j++);}
}
int main(){
	RCC->AHB1ENR |= 0x5;
	GPIOA->MODER |= 0x400;
	GPIOC->MODER |= 0x0;
	while(1){

		if(GPIOC->IDR & 0X2000){
			GPIOA->BSRR |=0x200000;

			delay(50);
			}
			else{
				GPIOA->BSRR |=0x20;
				delay(50);
		}

	}
}
#endif

//using HAL Library
void delay(int T)
{
	int i;
	while(T--)
	{
	for(i=0;i<4000;i++);
}}

int main()
{
	 RCC->AHB1ENR |= 0x5;
			GPIOA->MODER |= 0x400;
			GPIOC->MODER |= 0x0;

	while(1)
	{

		if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13))){

			GPIOA->BSRR |=(1<<5);
			delay(100);
			}
			else{
			GPIOA->BSRR |=(1<<21);
		}

	}
}

