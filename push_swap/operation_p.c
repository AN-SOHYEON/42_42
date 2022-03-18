

#include "push_swap.h"

void    ft_pa(t_stack *stack)
{
    t_Dnode *tempB;
    t_Dnode *endOfA;

    tempB = ft_dlstlast(stack->stack_b);
    endOfA = ft_dlstlast(stack->stack_a);
    tempB->left->right = NULL;
    ft_dlst_addback(&(stack->stack_a), tempB);
    write(1, "pa\n", 3);
}

void    ft_pb(t_stack *stack)
{
    t_Dnode *tempA;
    t_Dnode *endOfB;

    tempA = ft_dlstlast(stack->stack_a);
    endOfB = ft_dlstlast(stack->stack_b);
    tempA->left->right = NULL;
    ft_dlst_addback(&(stack->stack_b), tempA);
    write(1, "pb\n", 3);
}