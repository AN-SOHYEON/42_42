/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:44:36 by san               #+#    #+#             */
/*   Updated: 2021/09/07 22:51:24 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*temp;

	temp = (char *)str;
	if (!c)
		return (temp + ft_strlen(temp));
	else
	{
		len = 0;
		while (temp[len])
			len++;
		while (--len >= 0)
		{
			if (temp[len] == (char)c)
				return ((char *)&temp[len]);
		}
	}
	return (NULL);
}
