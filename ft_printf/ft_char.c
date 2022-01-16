
#include "libft.h"
#include "ft_printf.h"

int	write_char(va_list ap)
{
	int		count;
	char	to_print;
	char	*string;

	to_print = va_arg(ap, int);
	if (!to_print)	//to_printf가 널이면 널을 출력하고, 한개 출력했으니까 1만 count
	{
		write(1, &to_print, 1);
		return (1);
	}
	string = ft_calloc(sizeof(char), 2);
	string[0] = to_print;
	count = send_output(string);
	free(string);
	return (count);
}

int	write_str(va_list ap)
{
	char	*string;
	int		count;
	char	*pointer;

	pointer = va_arg(ap, char *);
	if (!pointer)	//에러처리
		return (write(1, "(null)", 6));
	string = ft_strdup(pointer);	//가변인자에 있던 값을 복사해서 string에 담음.
	count = send_output(string);
	free(string);
	return (count);
}

int	write_percent(void)
{
	return (write(1, "%", 1));
}
