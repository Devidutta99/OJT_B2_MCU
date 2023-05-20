/*
Application: USART/UART
Problem statement: Code for transmission of data using register code.

Author: Devidutta Kabisatapathy 
*/

#include <stdint.h>
#include<stdio.h>
usart_transmit(unsigned char);

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define GPIOAEN (1U<<0)
#define USART2EN (1U<<17)

uint32_t *portAEnable = (uint32_t *)0x40023830;
uint32_t *APB1ENR =(uint32_t *)0x40023840;
uint32_t *GPIOA_MODER =(uint32_t *)0x40020000;
uint32_t *GPIOA_AFRL =(uint32_t *)0x40020020;
uint32_t *USART2_BRR =(uint32_t *)0x40004408;
uint32_t *USART_CR1 =(uint32_t *)0x4000440c;
uint32_t *USART2_SR =(uint32_t *)0x40004400;
uint32_t *USART_DR =(uint32_t *)0x40004404;


usart_init(){
	*portAEnable = GPIOAEN;
	*GPIOA_MODER &= ~(1<<4);
	*GPIOA_MODER |= (1<<5);

	*APB1ENR = USART2EN;

	*GPIOA_AFRL |= (1<<8);
	*GPIOA_AFRL |= (1<<9);
	*GPIOA_AFRL |= (1<<10);
	*GPIOA_AFRL |= (1<<11);

	*USART2_BRR |= 0X683;

	*USART_CR1 |= 0X8;
	*USART_CR1 |= 0X2000;

}
usart_transmit(unsigned char ch){
	while(!(*USART2_SR & 0x80));
	USART_DR= ch & 0xff;

}

delay(int t){
	while(t--){
		for(int i=0;i<3000;i++);
	}
}
int main(void)
{
    usart_init();
    while(1){
    	//usart_transmit('g');
    	usart_transmit("Hello\r\n");
    	delay(500);
    }
}
