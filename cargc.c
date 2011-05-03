#include <stdio.h>

int *registers;

int main()
{
	registers = malloc(4*sizeof(int));

	print_regs();
	read_registers();
	print_regs();

	return 0;
}

void print_regs()
{
	printf("%d, %d, %d, %d\n", registers[0], registers[1], registers[2], registers[3]);
}

int GCalloc(int size)
{
	
}

int GCfree(int *ptr)
{
	
}

void read_registers(void)
{
	int r;
	asm ("movl %%eax, %0\n" :"=r"(r));
	registers[0] = r;
	
	asm ("movl %%ebx, %0\n" :"=r"(r));
	registers[1] = r;
	
	asm ("movl %%ecx, %0\n" :"=r"(r));
	registers[2] = r;
	
	asm ("movl %%edx, %0\n" :"=r"(r));
	registers[3] = r;
}