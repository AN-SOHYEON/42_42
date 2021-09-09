/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:00 by san               #+#    #+#             */
/*   Updated: 2021/09/08 00:34:06 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	num_dst;
	size_t	num_src;

	i = 0;
	num_dst = ft_strlen(dst);
	num_src = ft_strlen(src);
	if (size < (num_dst + 1))
		return (num_src + size);
	else
	{
		while (*dst)
			dst++;
		while (*(src + i))
		{
			if (i >= (size - num_dst - 1))
				break ;
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
		return (num_src + num_dst);
	}
}
