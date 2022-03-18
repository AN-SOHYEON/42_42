
#include "push_swap.h"


int         ft_dlstsize(t_Dnode *node)
{
    int size;
    t_Dnode *temp;

    size = 0;
    temp = node;
    while (temp)        //*temp로도 바꿔서 해보기
    {
        size++;
        temp = temp->right;
    }
    return (size);
}

void    ft_dlstdel_one(t_Dnode *node)
{
    if (!node)
        return ;
    free(node);
}

void    ft_dlstdel_all(t_Dnode **stack)
{
    t_Dnode *delnode;

    if (!stack)
        return ;
    while (*stack)
    {
        delnode = *stack;
        *stack = (*stack)->right;
        ft_dlstdel_one(delnode);
    }
}

// 이것이 필요한가 void    ft_dlstdel_front
