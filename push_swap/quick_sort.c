

#include "push_swap.h"

void    swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int partition(int)