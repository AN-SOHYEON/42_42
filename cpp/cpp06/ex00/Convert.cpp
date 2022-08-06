/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:35 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:58:36 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(std::string value)
{
	this->value = value;
}

Convert::~Convert()
{
}

Convert::Convert(const Convert &convert)
{
	this->value = convert.getValue();
}

Convert	&Convert::operator=(const Convert &convert)
{
	this->value = convert.getValue();
	return (*this);
}

void	Convert::convertChar(double d)
{
	if (isNanInf())
	{
		std::cout << "char   : " << "impossible" << std::endl;
	}
	else if ((d >= 0 && d < 33) || (d >= 127 && d < 128))
	{
		std::cout << "char   : " << "Non displayable" << std::endl;
	}
	else if (d >= 128)
	{
		std::cout << "char   : " << "impossible" << std::endl;
	}
	else 
	{
		char	c;
		c = static_cast<char>(d);
		std::cout << "char   : " << c << std::endl;
	}	
}

bool	Convert::intBound(double d)
{
	if (d > 2147483648)
		return (false);
	if (d < -2147483647)
		return (false);
	return (true);
}

bool	Convert::isNanInf()
{
	if (value.compare("nan") == 0)
		return (true);
	if (value.compare("nanf") == 0)
		return (true);
	if (value.compare("inf") == 0)
		return (true);
	if (value.compare("inff") == 0)
		return (true);
	return (false);
}

void	Convert::convertInt(double d)
{
	if (isNanInf() || !intBound(d))
	{
		std::cout << "int    : " << "impossible" << std::endl;
	}
	else
	{
		std::cout << "int    : " << static_cast<int>(d) << std::endl;
	}
}

void	Convert::convertFloat(double d)
{
	if ((findd('.') < 0 && !isNanInf()) || (findd('.') > -1 && value.length() == 1))
	{
		std::cout << "float  : " << static_cast<float>(d) << ".0f" << std::endl;
	}
	else
	{
		std::cout << "float  : " << static_cast<float>(d) << "f" << std::endl;
	}
}

void	Convert::convertDouble(double d)
{
	if ((findd('.') < 0 && !isNanInf()) || (findd('.') > -1 && value.length() == 1))
	{
		std::cout << "double : " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "double : " << d << std::endl;
	}
}


void	Convert::conversion()
{
	if (value.length() == 1)
	{
		int	i = static_cast<int>(value[0]);
		if ((i > 32 && i < 48) || (i > 57 && i < 127))
		{
			std::cout << "char   : " << static_cast<char>(i) << std::endl;
			double d = static_cast<double>(i);
			convertInt(d);
			convertFloat(d);
			convertDouble(d);
			return ;
		}	
	}
		double str_to_d = strtod(value.c_str(), NULL);
		convertChar(str_to_d);
		convertInt(str_to_d);
		convertFloat(str_to_d);
		convertDouble(str_to_d);
}

int		Convert::findd(char c)
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

std::string Convert::getValue() const
{
	return (this->value);
}
