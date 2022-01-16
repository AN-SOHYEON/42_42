
#include "libft.h"
#include "ft_printf.h"

static size_t	ft_uintlen(unsigned int i)
{
	size_t	size;

	size = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		size++;
		i = i / 10;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int n)
{
	size_t		i;
	size_t		minus;
	char		*p;

	i = ft_uintlen(n);
	minus = n < 0;
	i += minus;
	p = (char *) malloc(sizeof(char) * i + 1);
	if (p == NULL)
		return (NULL);
	p[i] = '\0';
	if (minus)
		p[0] = '-';
	while (--i != (minus - 1))
	{
		if ((n % 10) < 0)
			p[i] = ((n % 10) * -1) + 48;
		else
			p[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (p);
}

int	write_uint(va_list ap)
{
	char				*string;
	unsigned int		integer;
	int					count;

	integer = va_arg(ap, unsigned int);
	string = ft_uitoa(integer);
	count = send_output(string);
	free(string);
	return (count);
}

int	write_int(va_list ap)
{
	char	*string;
	int		integer;
	int		count;

	integer = va_arg(ap, int);
	string = ft_itoa(integer);
	count = send_output(string);
	free(string);
	return (count);
}