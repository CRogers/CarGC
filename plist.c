#include "plist.h"

plist *create_plist(int initialSize)
{
    plist *list = malloc(sizeof(*list));
    list->size = 0;
    list->MAXSIZE = initialSize;
    list->items = malloc(initialSize*sizeof(int));

    return list;
}

void add_plist(plist *list, int itemPtr)
{
    list->size++;

    // If plist is too small, resize it
    if(list->size > list->MAXSIZE)
    {
        list->MAXSIZE *= 2;
        list->items = (int*)realloc(list->items, list->MAXSIZE*sizeof(int*));
    }

    list->items[(list->size)-1] = itemPtr;
}

void print_items(plist *list)
{
    printf("[");
    for(int i = 0; i < list->size; i++)
        printf("%d, ", list->items[i]);
    printf("]\n");
}

int *get_plist(plist *list, int index)
{
    if(index >= list->size)
        return 0;

    return list->items[index];
}

void set_plist(plist *list, int index, int itemPtr)
{
    if(index < list->size)
        list->items[index] = itemPtr;
}
