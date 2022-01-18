/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:31:35 by san               #+#    #+#             */
/*   Updated: 2021/09/07 12:55:45 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t num)
{

	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (num == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		tmp_dst = (unsigned char*)dst;
		tmp_src = (unsigned char*)src;
		while (num--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		tmp_dst = (unsigned char*)dst + (num - 1);
		tmp_src = (unsigned char*)src + (num - 1);
		while (num--)
			*tmp_dst-- = *tmp_src--;
	}
	return (dst);
}
