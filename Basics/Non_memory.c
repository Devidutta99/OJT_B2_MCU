/*
Application: Inline Assembly Code
Problem Statement: 1. Addition of two numbers
                   2. Move the content of C variable to ARM register
                   3. Move the content of control register to C variable
                   4. Copy the content of pointer to another variable

Aurthor:Devidutta Kabisatapathy*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
//#if(0)
	//Addition of two numbers
    __asm volatile("LDR R1, =#0x20001000");
    __asm volatile("LDR R2, =#0x20001004");
    __asm volatile("LDR R0,[R1]");
    __asm volatile("LDR R1,[R2]");
    __asm volatile("ADD R0,R0,R1");
    __asm volatile("STR R0,[R2]");
//#endif()

#if(0)
    //Move the content of C variable to ARM register
    int val=40;
	__asm volatile("MOV R0,%0"::"r"(val));
#endif

#if(0)
	//Move the content of control register to C variable
	uint32_t control_reg;
	__asm volatile("MRS %0,CONTROL":"=r"(control_reg));
#endif

#if(0)
	//Copy the content of pointer to another variable
	int p1,*p2;
	p2=(int*)0x20000008;
	__asm volatile("LDR %0,[%1]":"=r"(p1):"r"(p2));
#endif
}
