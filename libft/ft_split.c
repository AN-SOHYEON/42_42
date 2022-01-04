/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:43:07 by san               #+#    #+#             */
/*   Updated: 2021/09/11 10:13:57 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static char        **mem_free(char **answer)
{
    size_t    i;

    i = 0;
    while (answer[i])
    {
        free(answer[i]);
        i++;
    }
    free(answer);
    return (NULL);
}

static size_t        count_word(char *s_temp, char c)
{
    size_t    word_count;
    size_t    i;
    size_t    s_len;

    word_count = 0;
    i = 0;
    s_len = ft_strlen(s_temp);
    while (i < s_len)
    {
        while (s_temp[i] == c && i < s_len)
            i++;
        if (i >= s_len)
            break ;
        while (s_temp[i] != c && i < s_len)
            i++;
        word_count++;
    }
    return (word_count);
}

static char            **find_word(char **answer, char *s, char c, size_t s_len)
{
    size_t    idx;
    size_t    i;
    size_t    j;

    i = 0;
    idx = 0;
    while (i < s_len)
    {
        while (s[i] == c && i < s_len)
            i++;
        if (i >= s_len)
            return (answer);
        j = i;
        while (s[j] != c && j < s_len)
            j++;
        answer[idx++] = ft_substr(s, i, j - i);
        if (!answer[idx - 1])
        {
            mem_free(answer);
            return (NULL);
        }
        i = j;
    }
    answer[idx] = NULL;
    return (answer);
}

char                **ft_split(char const *s, char c)
{
    char    **answer;
    size_t    s_len;
    char    *s_temp;
    
    if (!s)
        return (NULL);
    s_temp = (char *)s;
    s_len = ft_strlen(s_temp);
    answer = ft_calloc(sizeof(char *), count_word(s_temp, c) + 1);
    if (!answer)
        return (NULL);
    answer = find_word(answer, s_temp, c, s_len);
    return (answer);
}

/*
int        main(int argc, const char *argv[])
{
    char    **tabstr1;
    char    **tabstr2;
    char    **tabstr3;
    char    **tabstr4;
    char    **tabstr5;
    int        i;

    printf("1\n");
    i = 0;
    tabstr1 = ft_split("          ", ' ');
    while (tabstr1[i] != NULL)
    {
        printf("    %s\n", tabstr1[i]);
        i++;
    }
    printf("\n\n");


    printf("2\n");
    i = 0;
    tabstr2 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
    while (tabstr2[i] != NULL)
    {
        printf("    %s\n", tabstr2[i]);
        i++;
    }
    printf("\n\n");




    printf("3\n");
    i = 0;
    tabstr3 = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
    while (tabstr3[i] != NULL)
    {
        printf("    %s\n", tabstr3[i]);
        i++;
    }
    printf("\n\n");



    printf("4\n");
    i = 0;
    tabstr4 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
    while (tabstr4[i] != NULL)
    {
        printf("    %s\n", tabstr4[i]);
        i++;
    }
    printf("\n\n");




    printf("5\n");
    i = 0;
    tabstr5 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
    while (tabstr5[i] != NULL)
    {
        printf("    %s\n", tabstr5[i]);
        i++;
    }
    printf("\n\n");


    return (0);
}
*/

