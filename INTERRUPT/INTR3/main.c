/*
Application: Interrupt
Problem statement: Generation of interrupt using register code

Author: Devidutta Kabisatapathy 
*/
#include"main.h"
#include<stm32f4xx.h>
void EXTI1_IRQHandler(void)
{
   GPIOA->ODR ^= 0x40;		//ISR functionality
   for(int i=0;i<10000;i++);  //Delay
	   EXTI->PR |= 0x2;		//Return back from ISR to Main prog
}
int main()
{
   __disable_irq();						//Disable the IRQ
   RCC->AHB1ENR |= 0x1;					//Enable clock for PA
   GPIOA->MODER |= 0x1000;				//Set output for PA6
   RCC->APB2ENR|=0X4000;
   SYSCFG->EXTICR[0] |= 0x0;			//Enable SYSGFG for trigger the interrupt
   EXTI->IMR |= 0x2;					//Make mask pin set to 1 of corresponding IRQ -PIN
   EXTI->FTSR |= 0x2;				//Trigger the interrupt on falling edge
   NVIC_EnableIRQ(EXTI1_IRQn);		//Generate IRQ
   __enable_irq();						//Enable the request line
while(1);
}
#if(0)
#include "main.h"


/* Function to handle EXTI line[9:5] interrupts */
void EXTI9_5_IRQHandler(void);


int main()
{
	/* Disable the interrupt first */
	__disable_irq();

	/* Enable Clock for GPIOA */
	RCC->AHB1ENR |= (1 << 0);

	/* Enable Clock for SYSCFG */
	RCC->APB2ENR |= (1 << 14);

	/* Make GPIOA PIN 8 General purpose output */
	GPIOA->MODER |= (1 << 16);

	/* Enable the SYSCFG_EXTICR2 register */
	SYSCFG->EXTICR[1] |= (1 << 13);

	/* Unmask the interrupt request from input line PC7 */
	EXTI->IMR |= (1 << 7);

	/* Enable Falling Edge Trigger for input line PC7 */
	EXTI->RTSR |= (1 << 7);

	/* Enable interrupt for EXTI Line 7, which maps to PC7 */
	__NVIC_EnableIRQ(EXTI9_5_IRQn);

	/* Enable the interrupt */
	__enable_irq();

	while(1)
	{
		/* Do nothing here */
	}
}

/* Function to handle EXTI line[9:5] interrupts */
void EXTI9_5_IRQHandler(void)
{
	/* Toggle the state of GPIOA PIN 8 */
	GPIOA->ODR ^= (1 << 8);

	/* A small delay to avoid bouncing effect */
	for(uint32_t i = 0; i < 10000; i++);

	/* Clear the interrupt flag for EXTI Line 13 */
	EXTI->PR |= (1 << 7);
}
#endif
