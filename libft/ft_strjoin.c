/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:03:33 by san               #+#    #+#             */
/*   Updated: 2021/08/30 22:39:56 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *strs, char const *sep)
{
	char			*ret;
	int				i;
	int				size;
	int				j;

	size = ft_strlen((char *)sep) + ft_strlen((char *)strs);
	ret = (char *)ft_calloc(sizeof(char), (ft_strlen((char *)sep) 
				+ ft_strlen((char *)strs)) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < ft_strlen((char *)strs))
		ret[i] = strs[i];
	j = -1;
	while (++j < ft_strlen((char *)sep))
		ret[i + j] = sep[j];
	ret[i + j] = 0;
	return (ret);
}
