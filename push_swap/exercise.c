long long ft_atoi(char *argv)
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

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char *a = "-3147483700";
    printf("result: %lld\n", ft_atoi(a));
    printf("result_ori: %d\n", atoi(a));

    return(0);    
}