/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:23:53 by san               #+#    #+#             */
/*   Updated: 2021/09/08 23:58:46 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char *ft_itoa_real(char *number, int n)
{
	char	*temp;
	int		len;

	temp = (char *)malloc(sizeof(char) * ft_strlen(number));
	if (!temp)
		return (NULL);
	len = ft_strlen(number);
	if (n < 0)
	{
		temp[0] = '-';
		n = -n;
	}
	while (--len >= 0 && n > 0)
	{
		temp[len] = (n % 10) + '0';
		n = n / 10;
	}
	temp[ft_strlen(number)] = '\0';
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		num_len;

	num_len = numlen(n);
	number = malloc(sizeof(char) * (num_len + 2));
	if (!number)
		return (NULL);
	ft_memset(number, 9, num_len);
	if (n == 0)
	{
		ft_strlcpy(number, "0\0", 2);
		return (number);
	}
	if (n == -2147483648)
		ft_strlcpy(number, "-2147483648\0", 12);
	else
		number = ft_itoa_real(number, n);
	return (number);
}
