/*
Application: Access Level
Problem Statement: Change the access level from PAL to NPAL

Aurthor:Devidutta Kabisatapathy*/
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void generate_interrupt(){
	  uint32_t *pSTIR=(uint32_t*)0xE000EF00;	//these are some arm cortex-m4 processors system control register addresses which can only be accessed in PAL
	  uint32_t *pISER0=(uint32_t*)0xE000E100;	// any attempt to change the contents of these registers from being in NPAL will cause a processor fault exception

	  //ENABLE IRQ3 INTERRUPT
	  *pISER0|=(1<<3);

	  //GENERATE AN INTERRUOT FOR IRQ3
	  *pSTIR=(3 & 0X1FF);
}
void change_accesslevel(){
	__asm volatile("MRS R0,CONTROL");
	__asm volatile("ORR R0,R0,#0x01");
	__asm volatile("MSR CONTROL,R0");
}
int main(void)
{
	printf("In thread mode: before interrupt\n");
	change_accesslevel();
	generate_interrupt();

	printf("In thread mode: after interrupt\n");
}
void RTC_WKUP_IRQHandler(void){
	printf("In handler mode:ISR\n");
}
void HardFault(){
	printf("Hard fault detected\n");
	while(1);
}
