#include <stdio.h>
#include <stdlib.h>
#include "plist.h"

int main()
{
    int *regs = calloc(4, sizeof(int));

	print_regs(regs);
	read_regs(regs);
	print_regs(regs);

	struct range *rs = read_maps();

    plist *list = create_plist(1);
    printf("size: %d, MAXSIZE: %d\n", list->size, list->MAXSIZE);

    for(int i = 0; i < 128; i++)
        add_plist(list, i);

    for(int i = 0; i < list->size; i++)
        printf("%d\n",get_plist(list, i, i));

	/*for(int i = 0; i < rs && *((int*)rs[i]) != 0; i++)
		printf("Start: %ld, End: %ld", rs[i].start, rs[i].end);*/

	return 0;
}
