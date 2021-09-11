/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:06:43 by san               #+#    #+#             */
/*   Updated: 2021/09/06 17:14:57 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	long long	len;
	char		*ret;

	len = 0;
	while (src[len])
		len++;
	ret = (char *)malloc(len * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}
