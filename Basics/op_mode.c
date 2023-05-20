/*
Application: Operational mode
Problem Statement: Examine the two operational modes.

Aurthor:Devidutta Kabisatapathy*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void generate_interrupt(){
	  uint32_t *pSTIR=(uint32_t*)0xE000EF00;
	  uint32_t *pISER0=(uint32_t*)0xE000E100;

	  //ENABLE IRQ3 INTERRUPT
	  *pISER0|=(1<<3);

	  //GENERATE AN INTERRUOT FOR IRQ3
	  *pSTIR=(3 & 0X1FF);
}
int main(void)
{
    /* Loop forever */
	//for(;;);
	printf("In thread mode: before interrupt\n");

	generate_interrupt();
	printf("In thread mode: after interrupt\n");
}
void RTC_WKUP_IRQHandler(void){
	printf("In handler mode:ISR\n");
}


