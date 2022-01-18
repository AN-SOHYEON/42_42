#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>


int	    ft_ptf_putnbr(unsigned long l, unsigned int base, char caseflag);
int     ft_printf_string(char *s);
int     ft_printf_char(char c);
int     ft_printf_pointer(void *p);
int     ft_printf_int(int i);
int     ft_printf_hex(unsigned long h, char format);
int	ft_printf_num(unsigned long l, unsigned int base, char upper);
int ft_printf_uint(unsigned long ui);



int	ft_printf(const char *fmt, ...);

#endif