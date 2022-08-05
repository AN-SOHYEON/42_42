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

char	findType(std::string value)
{
	int	len = value.length();
	
	switch (len)
	{
		case (0):
			return (NULL);
		case (1):
			if (value[0] > 32 || value[0] < 127)
				return ('c');
			else 
				return ('i');
		default :
			if (value.find(".") < 0)
				return ('i');
			else
			{
				if (value.find("f") < 0)
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
	Convert convert(findType(value), value);


	return (0);
}
