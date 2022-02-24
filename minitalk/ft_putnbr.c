

#include "minitalk.h"

static void	ft_putnbr_fd_real(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd_real(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		ft_putnbr_fd_real(n);
	}
}
