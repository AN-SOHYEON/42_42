
#include "push_swap.h"

int find_middle(int size, t_Dnode *stack_a, int rank)
{
    int index;
    t_Dnode *temp;
    t_Dnode *cmp_temp;
    int small;

    index = 0;
    temp = stack_a;
    while (temp)
    {
        small = 0;
        cmp_temp = temp->right;
        while (cmp_temp)
        {
            if ((temp->data) > (cmp_temp->data))
                small++;
            cmp_temp = cmp_temp->right;
        }
        if (small == rank)
            break;
        temp = temp->right;
        index++;
    }
    return (index);
}//   이거 큌소트 사용하는 걸로 바꾸기

int find_pivot(t_stack *stack)
{
    int index;
    int size;
    int rank;

    size = ft_dlstsize(stack->stack_a);
    if ((size % 2) == 0)
        rank = size / 2;
    if ((size % 2) == 1)
        rank = (size / 2) + 1;
    index = find_middle(size, stack->stack_a, rank);
    return (index);
}