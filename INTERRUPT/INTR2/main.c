/*
Application: Interrupt
Problem statement: Generation of interrupt using register code

Author: Devidutta Kabisatapathy 
*/
#include"main.h"
#include<stm32f4xx.h>
void EXTI15_10_IRQHandler(void)
{
   GPIOA->ODR ^= 0x20;		//ISR functionality
   for(int i=0;i<3000000;i++);  //Delay
	   EXTI->PR |= 0x2000;		//Return back from ISR to Main prog
}
int main()
{
   __disable_irq();						//Disable the IRQ
   RCC->AHB1ENR |= 0x5;					//Enable clock for PA and PC
   GPIOA->MODER |= 0x400;				//Set output for PA5
   RCC->APB2ENR|=0X4000;
   SYSCFG->EXTICR[3] |= 0x20;			//Enable SYSGFG for trigger the interrupt
   EXTI->IMR |= 0x2000;					//Make mask pin set to 1 of corresponding IRQ -PIN
   EXTI->FTSR |= 0x2000;				//Trigger the interrupt on falling edge
   NVIC_EnableIRQ(EXTI15_10_IRQn);		//Generate IRQ
   __enable_irq();						//Enable the request line
while(1);
}
