/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:48:06 by san               #+#    #+#             */
/*   Updated: 2021/09/07 11:40:03 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	
	tmp1 = (unsigned char *)ptr1;
	tmp2 = (unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (tmp1[i] != tmp2[i])
			return(tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
