#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct  s_Dnode
{
    struct s_Dnode *left;
    int data;
    struct s_Dnode *right;
}               t_Dnode;

typedef struct  s_stack
{
    t_Dnode     *stack_a;
    t_Dnode     *stack_b;
}               t_stack;

//validation
long long ft_atoll(char *argv);
int ft_is_not_num(char *argv);
int ft_is_over_int(long long num);
int ft_is_duplicate(int ac, char **argv);

//libft0
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t len, size_t size);

//libft1
static char        **mem_free(char **answer);
static size_t        count_word(char *s_temp, char c);
static char            **find_word(char **answer, char *s, char c, size_t s_len);
char                **ft_split(char const *s, char c);



//d_list
t_Dnode     *ft_dlstnew(char *data);
t_Dnode     *ft_dlstlast(t_Dnode *node);
void    ft_dlst_addback(t_Dnode **stack, t_Dnode *newnode);
void    ft_dlst_addfront(t_Dnode **stack, t_Dnode *newnode);
int         ft_dlstsize(t_Dnode *node);
void    ft_dlstdel_one(t_Dnode *node);
void    ft_dlstdel_all(t_Dnode **stack);

//operation_s
void    ft_sa(t_stack *stack);
void    ft_sb(t_stack *stack);
void    ft_ss(t_stack *stack);

//operation_p
void    ft_pa(t_stack *stack);
void    ft_pb(t_stack *stack);

//operation_r
void    ft_ra(t_stack *stack);
void    ft_rb(t_stack *stack);
void    ft_rr(t_stack *stack);

//operation_rr
void    ft_rra(t_stack *stack);
void    ft_rrb(t_stack *stack);
void    ft_rrr(t_stack *stack);







#endif