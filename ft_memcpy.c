/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:17:58 by san               #+#    #+#             */
/*   Updated: 2021/07/31 16:21:29 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < num)
		*new_dest++ = *new_src++;
	return (dest);
}
