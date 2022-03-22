

#include "push_swap.h"
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