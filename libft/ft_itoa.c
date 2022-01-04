/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:23:53 by san               #+#    #+#             */
/*   Updated: 2021/09/11 09:36:28 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t    numlen(int n)
{
    size_t    len;

    if (n == 0)
        return (1);
    len = 0;
    if (n < 0)
        len++;
    while (n)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa_real(char *number, int n, size_t num_len)
{
    size_t        i;

    i = 0;
    if (n < 0)
    {
        number[0] = '-';
        n = -n;
        i++;
    }
//    printf("num_len : %zu\n", num_len); //
    while (num_len > i)
    {
        number[num_len - 1] = (n % 10) + '0';
//        printf("num_len == %zu :    %s\n",num_len, &number[num_len - 1]);
        num_len--;
        n = n / 10;
    }
    return (number);
}

char    *ft_itoa(int n)
{
    char    *number;
    size_t    num_len;

    num_len = numlen(n);
    number = ft_calloc((num_len + 1), sizeof(char));
    if (!number)
        return (NULL);
    number[num_len] = '\0';
    if (n == -2147483648)
        ft_strlcpy(number, "-2147483648\0", 12);
    else
        ft_itoa_real(number, n, num_len);
    return (number);
}


//#include <stdio.h>
/*
int main ()
{

    char *str1;
    char *str2;

    str1 = ft_itoa(2147483647);
    str2 = ft_itoa(-2147483648);
    printf("%s\n", str1);
    printf("%s\n", str2);

    int i = -10;
    while (i <= 10)
    {
        printf("%s\n", ft_itoa(i));
        i++;
    }

return (0);
}
*/
