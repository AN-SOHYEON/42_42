

#include "push_swap.h"

void    ft_rra(t_stack *stack)
{
    t_Dnode *beginOfA;

    if (ft_dlstsize(stack->stack_a) < 2)
        return ;
    beginOfA = stack->stack_a;
    beginOfA->right->left = NULL;
    stack->stack_a = beginOfA->right;
    ft_dlst_addback(&(stack->stack_a), beginOfA);
    write(1, "rra\n", 4);
}

void    ft_rrb(t_stack *stack)
{
    t_Dnode *beginOfB;

    if (ft_dlstsize(stack->stack_b) < 2)
        return ;
    beginOfB = stack->stack_b;
    beginOfB->right->left = NULL;
    stack->stack_b = beginOfB->right;
    ft_dlst_addback(&(stack->stack_b), beginOfB);
    write(1, "rrb\n", 4);
}

void    ft_rrr(t_stack *stack)
{
    ft_rra(stack);
    ft_rrb(stack);
    write(1, "rrr\n", 4);
}