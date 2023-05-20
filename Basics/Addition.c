/*
Application: Inline Assemvly Code
Problem Statement: Addition of two numbers

Aurthor:Devidutta Kabisatapathy*/
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int add(int a,int b){
	int c=0;
	__asm volatile("ADD %0,%1,%2":"=r"(c):"r"(a),"r"(b));
	return c;
}
int main(void)
{
	int c=add(5,7);
	printf("%d",c);

    /* Loop forever */
	for(;;);
}
