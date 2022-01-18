#include "ft_printf.h"

char    *ft_strupper(char *str_hex)
{
    int count;

    count = -1;
    while (str_hex[++count] != '\0')
    {
        if (str_hex[count] >= 97 && str_hex[count] <= 122)
			str_hex[count] = (str_hex[count] - 32);
	}
	return (str_hex);
}

char    *ul_to_hex(unsigned long hex)
{
    ssize_t		i;
	char		p[9];

	i = 8;
	p[i] = '\0';
	if (hex == 0)
	{
        ft_strdup("0"));
        return (p);
    }
	while (--i != -1 && hex != 0)
	{
		if ((hex % 16) < 10)
			p[i] = ((hex % 16)) + 48;
		else
			p[i] = (hex % 16) + 87;
		hex = hex / 16;
	}
	ft_strdup(&p[i + 1]);
    return (p);
}

int ft_printf_hex(unsigned long h, char format)
{
    int count;
    char *string;

    string = ul_to_hex(h);
    if (format == 'X')
        string = ft_strupper(string);
    count = write(1, string, ft_strlen(string));
    return (count);
}