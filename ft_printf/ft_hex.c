
#include "libft.h"
#include "ft_printf.h"

static char	*ft_strupcase(char *str)
{
	int	count;

	count = -1;
	while (str[++count] != '\0')
	{
		if (str[count] >= 97 && str[count] <= 122)
			str[count] = (str[count] - 32);
	}
	return (str);
}

static char	*ft_stox(size_t n)
{
	ssize_t		i;
	char		p[17];

	i = 16;
	p[i] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (--i != -1 && n != 0)
	{
		if ((n % 16) < 10)
			p[i] = ((n % 16)) + 48;
		else
			p[i] = (n % 16) + 87;
		n = n / 16;
	}
	return (ft_strdup(&p[i + 1]));
}

static char	*ft_uitox(unsigned int n)
{
	ssize_t		i;
	char		p[9];

	i = 8;
	p[i] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (--i != -1 && n != 0)
	{
		if ((n % 16) < 10)
			p[i] = ((n % 16)) + 48;
		else
			p[i] = (n % 16) + 87;
		n = n / 16;
	}
	return (ft_strdup(&p[i + 1]));
}
int	write_ptr(va_list ap)
{
	size_t			pointer;
	char			*string;
	char			*tmp_string;
	int				count;

	pointer = va_arg(ap, size_t);
	if (!pointer)
		return (write(1, "0x0", 3));
	tmp_string = ft_stox(pointer);
	string = ft_strjoin("0x", tmp_string);
	free(tmp_string);
	count = send_output(string);
	free(string);
	return (count);
}

int	write_hex(char converter, va_list ap)
{
	unsigned int	hex;
	char			*string;
	int				count;

	hex = va_arg(ap, unsigned int);
	string = ft_uitox(hex);
	if (converter == 'X')
		count = send_output(ft_strupcase(string));
	else
		count = send_output(string);
	free(string);
	return (count);
}