
#include "push_swap.h"

void    ft_sa(t_stack *stack)
{
    int temp_data;
    t_Dnode *temp_node;

    if (ft_dlstsize(stack->stack_a) < 2)
        return ;
    temp_node = ft_dlstlast(stack->stack_a);
    temp_data = temp_node->data;
    temp_node->data = temp_node->left->data;
    temp_node->left->data = temp_data;
    write(1, "sa\n", 3);
}

void    ft_sb(t_stack *stack)
{
    int temp_data;
    t_Dnode *temp_node;

    if (ft_dlstsize(stack->stack_b) < 2)
        return ;
    temp_node = ft_dlstlast(stack->stack_b);
    temp_data = temp_node->data;
    temp_node->data = temp_node->left->data;
    temp_node->left->data = temp_data;
    write(1, "sb\n", 3);
}

void    ft_ss(t_stack *stack)
{
    ft_sa(stack);
    ft_sb(stack);
    write(1, "ss\n", 3);
}