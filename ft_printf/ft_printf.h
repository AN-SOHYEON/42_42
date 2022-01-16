
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>


int		ft_printf(const char *format, ...);

int		send_output(char *string);

int		write_ap(char **string, va_list args);

int		write_char(va_list ap);


int		write_str(va_list ap);

int		write_int(va_list ap);

int		write_uint(va_list ap);


int		write_ptr(va_list ap);

int		write_hex(char converter, va_list ap);

int		write_percent(void);

#endif
