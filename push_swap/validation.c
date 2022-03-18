
#include "push_swap.h"

//validation
long long ft_atoll(char *argv)
{
    long long		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*argv == ' ' || *argv == '\n' || *argv == '\t'
		|| *argv == '\v' || *argv == '\f' || *argv == '\r')
		argv++;
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sign = sign * (-1);
		argv++;
	}
	while (*argv >= '0' && *argv <= '9')
	{
		result = (result * 10) + (*argv - '0');
		argv++;
	}
	return (sign * result);
}


//validation
int ft_is_not_num(char *argv)
{
	while (*argv)
	{
		if (*argv < '0' || *argv > '9')
			return (1);
		argv++;
	}
	return (0);
//한자리씩 검사하면서 숫자인지 확인하는 함수 만들기

//num 맞으면 0 반환
}

//validation
int ft_is_over_int(long long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0); //범위에 문제 없으면 0 반환 (정수범위이다.)
}

//validation
int ft_is_duplicate(int ac, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoll(argv[i]) == ft_atoll(argv[j]))	//ft_atoll안쓰면 왜 같은걸 모르지?
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}