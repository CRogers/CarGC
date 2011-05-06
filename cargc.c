#include <stdio.h>

struct range
{
	long start;
	long end;
};


void print_regs(int *regs)
{
	printf("eax: %d, ebx: %d, ecx: %d, edx: %d\n", regs[0], regs[1], regs[2], regs[3]);
}

int GCalloc(int size)
{

}

int GCfree(int *ptr)
{

}

void read_regs(int *regs)
{
	__asm__ ("movl %%eax, %0\n" :"=r"(regs[0]));
	__asm__ ("movl %%ebx, %0\n" :"=r"(regs[1]));
	__asm__ ("movl %%ecx, %0\n" :"=r"(regs[2]));
	__asm__ ("movl %%edx, %0\n" :"=r"(regs[3]));
}

struct range *read_maps()
{
	FILE *fp = fopen("/proc/self/maps", "r");
	struct range *rs = calloc(128, sizeof(*rs));

	for(int i = 0; getc(fp) == EOF; i++)
	{
		char c;
		long start, end;

		while((c = getc(fp)) != '-')
			start = start * 16 + (c - '0');

		while((c = getc(fp)) != ' ')
			end = end * 16 + (c - '0');

		while(getc(fp) != '\n');

		struct range r = { start, end };
		rs[i] = r;
	}

	return rs;
}
