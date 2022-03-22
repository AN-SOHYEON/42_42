

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (sign * result);
}

size_t	ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	
	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t len, size_t size)
{
	void	*mem;

	mem = malloc(len * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * len);
	return (mem);
}