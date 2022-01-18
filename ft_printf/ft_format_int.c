#include "ft_printf.h"


int	ft_printf_num(unsigned long l, unsigned int base, char upper)
{
	long	n;
	int		count;
	char	num_char;

	count = 0;
	n = 1;
	while (l / n >= base)
		n = n * base;
	while (n != 0)
	{
		if ((l / n) < 10)
			num_char = (l / n) + '0';
		else if (upper == 1)
			num_char = (l / n) - 10 + 'A';
		else
			num_char = (l / n) - 10 + 'a';
		count = count + write(1, &num_char, 1);
		l %= n;
		n /= base;
	}
	return (count);
}

int ft_printf_uint(unsigned long ui)
{
	int count;

	count = 0;
	count = ft_printf_num(ui, 10, 0);
	return (count);
}


int ft_printf_int(int i)
{
	int		count;
	long	l;

	count = 0;
	l = i;
	if (i < 0)
	{
		l = l * -1;
		count = count + write(1, "-", 1);
	}
	count = count + ft_printf_num(l, 10, 0);
	return (count);
}
