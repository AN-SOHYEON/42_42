/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:43:07 by san               #+#    #+#             */
/*   Updated: 2021/09/09 00:10:46 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int		word_count;

	word_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_count);
}

char	*find_word(char *word, char *s_temp, char c)
{
	int		i;

	i = 0;
	while (s_temp[i] != c)
	{
		word[i] = s_temp[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int		find_word_len(char *s_temp, char c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s_temp[i] && s_temp[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	char	*s_temp;
	
	s_temp = (char *)s;
	ans = (char **)malloc(sizeof(char *) * (count_word(s_temp, c) + 1));
	if (!ans)
		return (NULL);
	i = 0;
	while (*s_temp)
	{
		while (*s_temp && *s_temp == c)
			s_temp++;
		if (!*s_temp)
			break ;
		ans[i] = (char *)malloc(sizeof(char) * find_word_len(s_temp, c));
		if (!ans[i])
			return (NULL);
		ans[i] = find_word(ans[i], s_temp, c);
		i++;
		while (*s_temp && *s_temp != c)
			s_temp++;
	}
	ans[i] = NULL;
	return (ans);
}
