/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:17:57 by san               #+#    #+#             */
/*   Updated: 2021/09/08 00:19:23 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*charcmp(char *str, char *to_find, size_t len)
{
	while (*str == *to_find && *str != 0 && *to_find != 0 && len > 0)
	{
		str++;
		to_find++;
		len--;
	}
	return (to_find);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cpy_li;
	char	*cpy_big;

	cpy_li = (char *)little;
	cpy_big = (char *)big;
	if (*cpy_li == 0)
		return (cpy_big);
	if (len == 0)
		return (0);
	while (*cpy_big && len > 0)
	{
		if (*cpy_big == *cpy_li)
		{
			if (charcmp(cpy_big, cpy_li, len) == (cpy_li + ft_strlen(cpy_li)))
				return (cpy_big);
		}
		cpy_big++;
		len--;
	}
	return (0);
}
