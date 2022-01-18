#include "ft_printf.h"



int ft_printf_hex(unsigned long h, char format)
{
    int count;

    count = 0;
    if (format == 'x')
        count = ft_printf_num(h, 16, 0);
    else
        count = ft_printf_num(h,16, 1);
    return (count);
}