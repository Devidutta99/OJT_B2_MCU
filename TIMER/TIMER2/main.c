#include"main.h"

void timer_delay(){
	RCC->APB1ENR |= 0x1;
	TIM2->PSC = 1600-1;
	TIM2->ARR = 10000-1;
	TIM2->CNT = 0;
	TIM2->CR1 = 1;
}



int main(){
	/*ENABLE GPIO*/
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x400;
	timer_delay();

	while(1){
		while(!(TIM2->SR & 1));
		GPIOA->ODR ^= 0x20;
		TIM2->SR = 0;
	}

}
