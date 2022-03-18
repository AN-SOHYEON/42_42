

#include "push_swap.h"

void    ft_ra(t_stack *stack)
{
    t_Dnode *endOfA;

    if (ft_dlstsize(stack->stack_a) < 2)
        return ;
    endOfA = ft_dlstlast(stack->stack_a);
    endOfA->left->right = NULL;
    ft_dlst_addfront(&(stack->stack_a), endOfA);
    write(1, "ra\n", 3);
}

void    ft_rb(t_stack *stack)
{
    t_Dnode *endOfB;

    if (ft_dlstsize(stack->stack_b) < 2)
        return ;
    endOfB = ft_dlstlast(stack->stack_b);
    endOfB->left->right = NULL;
    ft_dlst_addfront(&(stack->stack_b), endOfB);
    write(1, "rb\n", 3);
}

void    ft_rr(t_stack *stack)
{
    ft_ra(stack);
    ft_rb(stack);
    write(1, "rr\n", 3);
}