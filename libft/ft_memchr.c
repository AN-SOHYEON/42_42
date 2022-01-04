/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:36:33 by san               #+#    #+#             */
/*   Updated: 2021/09/06 17:13:55 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	while (num > 0)
	{
		if (*tmp == (unsigned char)value)
			return (tmp);
		num--;
		tmp++;
	}
	return (NULL);
}
