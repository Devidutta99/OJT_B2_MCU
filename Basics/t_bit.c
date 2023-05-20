/*
Application: T-bit
Problem Statement: Observation of changes in T-bit

Aurthor:Devidutta Kabisatapathy*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void change_accesslevel(){
	__asm volatile("MRS R0,CONTROL");
	__asm volatile("ORR R0,R0,#0x01");
	__asm volatile("MSR CONTROL,R0");
}
int main(void)
{

	printf("In thread mode: before interrupt\n");
	void (*funptr)(void);
	funptr=(void *)0x8000204;
	funptr();
	printf("In thread mode: after interrupt\n");
}
void RTC_WKUP_IRQHandler(void){
	printf("In handler mode:ISR\n");
}
