/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:50:15 by san               #+#    #+#             */
/*   Updated: 2021/09/07 22:47:45 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>


char	*ft_strchr(const char *str, int c)
{
	char	*temp;

	temp = (char *)str;
	if (c == '\0')
		return (temp + ft_strlen(temp));
	while (*temp)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	return (NULL);
}
