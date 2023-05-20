/*
Application: Stack Pointer
Problem Statement: Addition of four numbers using function

Aurthor:Devidutta Kabisatapathy*/
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
int add(uint32_t a,uint32_t b,uint32_t c,uint32_t d){
	return a+b+c+d;
}
int main(void)
{
	int ret;
	ret=add(1,2,3,4);
	printf("Result=%d\n",ret);
	printf("Hello");
    /* Loop forever */
	for(;;);
}
