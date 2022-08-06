/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:53 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:58:56 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int		findd(std::string value, char c)
{
	int	ret;
	int	len;

	ret = -1;
	len = value.length();
	for(int i = 0; i < len; i++)
	{
		if (c == value[i])
		{
			ret = i;
			return (ret);
		}
	}
	return (ret);
}

char	findType(std::string value)
{
	int	len = value.length();
	
	switch (len)
	{
		case (0):
			return ('\0');
		case (1):
			if (value[0] > 32 || value[0] < 127)
				return ('c');
			else 
				return ('i');
		default :
			if (findd(value, '.') < 0)
				return ('i');
			else
			{
				if (findd(value, 'f') < 0)
					return ('d');
				else
					return ('f');
			}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "put one parameter plz." << std::endl;
		return (1);
	}
	std::string	value = av[1];
	value.append("\0");
	try
	{
		Convert convert(findType(value), value);
		convert.conversion();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
