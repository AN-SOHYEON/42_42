/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:40:23 by san               #+#    #+#             */
/*   Updated: 2021/09/07 23:12:33 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		src_len;
	size_t		i;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	else if (size == 1)
		dest[0] = '\0';
	else
	{
		while (i < size - 1 && src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		while (src[i])
			i++;
	}
	return (i);
}
