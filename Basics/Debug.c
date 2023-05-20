/*
Application: Debugging
Problem Statement: To display the string on STM IDE console

Aurthor:Devidutta Kabisatapathy*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include<stdio.h>
int main(void)
{
    /* Loop forever */
	//for(;;);
	printf("Hello welcome to embedded world\n");
}
