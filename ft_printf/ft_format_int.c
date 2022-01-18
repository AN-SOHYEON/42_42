#include "ft_printf.h"



int ft_printf_uint(unsigned long ui)
{

}


int ft_printf_int(int i)
{
	char	*string;
	int		count;

	string = ft_itoa(i);
	count = write(1, string, ft_strlen(string));
	free(string);
	return (count);
}
