

#include "push_swap.h"

t_Dnode     *ft_dlstnew(char *data)         // make new node
{
    t_Dnode *newnode;

    newnode = (t_Dnode *)malloc(sizeof(t_Dnode));
    if (!newnode)
        exit(1);    /////////번호에 대해 알아보기 참고한 곳은 15를 씀
    newnode->left = NULL;
    newnode->data = ft_atoi(data);
    newnode->right = NULL;
    return (newnode);
}

t_Dnode     *ft_dlstlast(t_Dnode *node)
{
    t_Dnode     *temp;

    temp = node;
    while (temp && temp->right)
        temp = temp->right;
    return (temp);
}

void    ft_dlst_addback(t_Dnode **stack, t_Dnode *newnode)
{
    t_Dnode *last;

    if (!newnode)
        exit(15); //이거 꼭해야하는 부분인가?
    if (*stack)
    {
        last = ft_dlstlast(*stack);
        newnode->left = last;
        newnode->right = NULL;
        last->right = newnode;
    }
    else  // 스택이 아예비어있으면
    {
        newnode->left = NULL;
        newnode->right = NULL;
        *stack = newnode;   //  이거 쩜 이해 안가네
    }
}

void    ft_dlst_addfront(t_Dnode **stack, t_Dnode *newnode)
{
    if (!newnode)
        exit(15); //이거 꼭해야하는 부분인가?
    if (*stack)
    {
        newnode->right = *stack;
        (*stack)->left = newnode;
        newnode->left = NULL;
        *stack = newnode;
    }
    else
    {
        newnode->left = NULL;
        newnode->right = NULL;
        *stack = newnode;
    }
}


