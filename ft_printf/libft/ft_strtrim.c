/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:32:41 by san               #+#    #+#             */
/*   Updated: 2021/08/30 22:47:00 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isincluded(char a, char const *set)
{
	while (*set)
		if (a == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*begin;
	char	*until;
	size_t	len;

	begin = (char *)s1;
	until = begin + ft_strlen((char *)s1);
	while (*begin && isincluded(*begin, set))
		++begin;
	while (begin < until && isincluded(*(until - 1), set))
		--until;
	len = until - begin + 1;
	ret = malloc(len);
	if (!ret)
		return (0);
	ft_strlcpy(ret, begin, len);
	return (ret);
}
