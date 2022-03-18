
#include "push_swap.h"

#include <stdio.h>

void is_Error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void valid_args(int ac, char **argv)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (ft_is_not_num(argv[i]) != 0)     //atoi만 해서는 0인지, 숫자아닌 다른 입력값인지 알ㄱㅣ ㅎㅣㅁㄷㅡㄹㄷㅏ 따라서 is_alpha를 통해 걸러낸다.
			is_Error();
		if (ft_is_over_int(ft_atoll(argv[i])) != 0)
			is_Error();
		i++;
	}
	if (ft_is_duplicate(ac, argv) != 0)
		is_Error();
}

t_stack	*create_stack(int ac, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		ft_dlst_addback(&(stack->stack_a), ft_dlstnew(argv[i]));
		i++;
	}
	return (stack);
}

//
void    sa(t_stack *stack)
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

//
#include <stdio.h>
void	print_node(t_Dnode *head)
{
	if (head == NULL)
		printf("NULL\n");
	while (head != NULL)
	{
		printf("%d \n", head->data);
		head = head -> right;
	}
}

int main(int ac, char **argv)
{
	t_stack	*stack;

    if (ac < 3)	//여기 왜 3으로 했지?
        return (1);
    valid_args(ac, argv);
	stack =	create_stack(ac, argv);	
	
	printf("원본\n");//
	print_node(stack->stack_a);	//여기까지 잘나옴
	
//	index = find_pivot(stack);
//	sort(index, stack);
//  ft_dlstdel_allstack(stack);
    return (0);
}