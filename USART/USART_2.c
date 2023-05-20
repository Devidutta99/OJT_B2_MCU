/*
 * APPLICATION: USART
 * PROBLEM STATEMENT: Print a character or string
 * AUTHOR: Devidutta Kabisatapathy

 */

/* sTEPS TO FOLLOW THE USART -INTIALISATION
 * STEP1: enable clock access to GPIOA
 * STEP2: Set PA2 mode to alternative mode
 * STEP3: Set PA2 alternative function type to USART-Tx (AF07)
 * STEP4: Configure UART Module
 * STEP5: Configure UART baud rate*/

#include <stdint.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

 uint32_t *portAHB1ENR = (uint32_t *)0x40023830;
		uint32_t *portAPB1ENR =(uint32_t *)0x40023840;
		uint32_t *portAMODER =(uint32_t *)0x40020000;
		uint32_t *portAAFRL =(uint32_t *)0x40020020;
		uint32_t *portABRR =(uint32_t *)0x40004408;
		uint32_t *portACR1 =(uint32_t *)0x4000440c;
		uint32_t *portSR =(uint32_t *)0x40004400;
		uint32_t *portDR =(uint32_t *)0x40004404;

/*__io_putchar(unsigned char s){
	usart_transmit(s);
		return s;

}*/
		void usart_init(){

	// address intialisation


		//data intilisation
		    *portAHB1ENR =(0x01);
			*portAPB1ENR =(0x2000);
			*portAMODER =(0xA0);
			*portAAFRL=(0x7700);
			*portABRR =(0x683);
			*portACR1 =(0x2008);
			*portSR = (0x80);

}

usart_transmit(unsigned char s){
	while(!(*portSR & 0x80));
	portDR= s & 0xff;

}

int main(void)
{
	usart_init();
	usart_transmit('g');

}
