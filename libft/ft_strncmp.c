/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:52:46 by san               #+#    #+#             */
/*   Updated: 2021/09/11 00:52:56 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int        ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

    i = 0;
    if (n == 0)
        return (0);
    while (i < n && *s1 && *s2)
    {
        if (*s1 != *s2)
            break ;
        i++;
        s1++;
        s2++;
    }
    if (i == n)
        return (0);
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
