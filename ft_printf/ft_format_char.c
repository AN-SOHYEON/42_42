#include "ft_printf.h"

int ft_printf_pointer(void *p)
{
    int count;

    count = write(1, "0x", 2);
    count = count + ft_printf_num((unsigned long)p, 16, 0);
    return (count);
}

int ft_printf_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int     ft_printf_string(char *s)
{
    int count;

    count = 0;
    if (s == 0)
        count = count + write(1, "(null)", 6);
    else
    {
        while (s[count])
        {
            count++;
            if (count < 0)
                return (-1);
        }
        write (1, s, count);
    }
    return (count);
}