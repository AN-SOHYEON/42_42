/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:45:48 by san               #+#    #+#             */
/*   Updated: 2021/09/11 01:39:43 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	j;

	if (!s || len <= 0 || start >= ft_strlen(s))
	{
		ret = (char *)malloc(sizeof(char) * 1);
		*ret = '\0';
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (j < len)
	{
		ret[j] = s[start];
		start++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}



//int main()
//{
//	char* str;
//
//	str = ft_substr("Hello, 42Seoul!", 7, 2);
//	printf("ft : %s\n", str);
//	printf("or : %s\n", substr("Hello, 42Seoul!", 7, 2));
//
//	return 0;
//}
