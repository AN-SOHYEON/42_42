
#include "ft_printf.h"




int     ft_find_format(va_list *ap, const char *string)
{
    if (*string == 'c')
        return (ft_printf_char(va_arg(*ap, int)));
    else if (*string == 's')
        return (ft_printf_string(va_arg(*ap, char*)));
    else if (*string == 'p')
        return (ft_printf_pointer(va_arg(*ap, void *)));
    else if (*string == 'd' || *string == 'i')
        return (ft_printf_int(va_arg(*ap, int)));
    else if (*string == 'u')
        return (ft_printf_uint(va_arg(*ap, unsigned int)));
    else if (*string == 'x' || *string == 'X')
        return (ft_printf_hex(va_arg(*ap, unsigned int), *string));
    else if (*string == '%')
        return (write(1, "%", 1));
    else 
        return (write(1, &string, 1));      // -1리턴?
}

int     ft_printf(const char *string, ...)
{
    va_list ap;
    int     count;
    int     tmp_count;

    va_start(ap, string);
    count = 0;
    while (*string)
    {
        if (*string == '%')
        {
            string++;
            tmp_count = ft_find_format(&ap, string);
            if (tmp_count < 0)
                return (tmp_count);
                count = count + tmp_count;
        }
        else
            count = count + tmp_count;
        string++;
    }
    va_end(ap);
    return (count);
}