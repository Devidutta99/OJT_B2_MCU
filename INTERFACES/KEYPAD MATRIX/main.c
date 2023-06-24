/*
Application: 4X4 Keypad Matrix
Problem Statement: Register code programing for Keypad matrix

Aurthor:Madhulika Nayak*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(int T)
{
	int i;
	while(T--)
	{
	for(i=0;i<4000;i++);
	}
}


int main(void)
{
	uint32_t *portcMODER =(uint32_t *)0x40020800;
	uint32_t *portcAHB1ENR =(uint32_t *)0x40023830;
	uint32_t *portcIDR =(uint32_t *)0x40020810;
	uint32_t *portcODR =(uint32_t *)0x40020814;

	uint32_t *portcPUPDR =(uint32_t *)0x4002080c;

	//Enable the Peripheral clock for GPIOC

	//rows-pc0-pc3=output
	//columns-pc4-pc7=input

	*portcAHB1ENR |= 0x4;
	*portcMODER |= 0x55;
	*portcPUPDR |= 0x5500;


	while(1)
	{
		//Make R1 low
		*portcODR |= 0x0f;
		*portcODR &= ~(1<<0);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("1 pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("2 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("3 pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("A pressed\n");
		}

		*portcODR |= 0x0f;
		*portcODR &= ~(1<<1);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("4 pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("5 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("6 pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("B pressed\n");
		}

		*portcODR |= 0x0f;
		*portcODR &= ~(1<<2);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("7 pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("8 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("9 pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("C pressed\n");
		}

		*portcODR |= 0x0f;
		*portcODR &= ~(1<<3);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("* pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("0 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("# pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("D pressed\n");
		}

		//End Of While Loop
	}


    /* Loop forever */
	for(;;);
}
