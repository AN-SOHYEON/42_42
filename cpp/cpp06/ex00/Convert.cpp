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

void	Convert::convertChar()
{
	if (this->value[0] < 33 || this->value[0] == 127)
		c = "Non displayable";
	else if (this->value[0] > 127)
		c = "impossible";
	else 
		c = value;
	
	i = static_cast<int>(this->value[0]);
	f = static_cast<float>(this->value[0]);
	d = static_cast<double>(this->value[0]);

	std::cout << "char   : " << this->c << std::endl;
	std::cout << "int    : " << this->i << std::endl;
	std::cout << "float  : " << this->f << ".0f" << std::endl;
	std::cout << "double : " << this->d << ".0" << std::endl;
}

bool	Convert::IntBound()
{
	unsigned int	lim;

	if (value[0] == '-')
	{
		value = value.erase(0, 1);
		lim = strtoul(value.c_str(), NULL, 10);
		if (lim > 2147483647)
			return (false);
	}
	else
	{
		lim = strtoul(value.c_str(), NULL, 10);
		if (lim > 2147483648)
			return (false);
	}
	return (true);
}

void	Convert::convertInt()
{
	if (value.find("nan") > -1)
	{
		std::cout << "char   : " << "impossible" << std::endl;
		std::cout << "int    : " << "impossible" << std::endl;
		std::cout << "float  : " << "nanf" << std::endl;
		std::cout << "double : " << "nan" << std::endl;
		return ;
	}
	if (value.find("inf") > -1)
	{
		std::cout << "char   : " << "impossible" << std::endl;
		std::cout << "int    : " << "impossible" << std::endl;
		std::cout << "float  : " << "inff" << std::endl;
		std::cout << "double : " << "inf" << std::endl;
		return ;
	}
	if (!IntBound())
	{
		std::cout << "char   : " << "over int bound" << std::endl;
		std::cout << "int    : " << "over int bound" << std::endl;
		std::cout << "float  : " << "over int bound" << std::endl;
		std::cout << "double : " << "over int bound" << std::endl;
	}
	else
	{
		i = atoi(value.c_str());
		f = static_cast<float>(i);
		d = static_cast<double>(i);

		if (i < 33 || i == 127)
			c = "Non displayable";
		else if (i > 127)
			c = "impossible";
		else
			c = static_cast<char>(i);
		std::cout << "char   : " << this->c << std::endl;
		std::cout << "int    : " << this->i << std::endl;
		std::cout << "float  : " << this->f << ".0f" << std::endl;
		std::cout << "double : " << this->d << ".0" << std::endl;
	}
}

void	Convert::convertFloat()
{
	f = static_cast<float>(strtod(value.c_str(), NULL));
	d = static_cast<double>(f);

	if (!IntBound())
	{
		std::cout << "char   : " << "impossible" << std::endl;
		std::cout << "int    : " << "over int bound" << std::endl;
		std::cout << "float  : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
		return ;
	}		
	i = static_cast<int>(f);
	if (i < 33 || i == 127)
		c = "Non displayable";
	else if (i > 127)
		c = "impossible";
	else
		c = static_cast<char>(i);
	std::cout << "char   : " << this->c << std::endl;
	std::cout << "int    : " << this->i << std::endl;
	std::cout << "float  : " << this->f << "f" << std::endl;
	std::cout << "double : " << this->d << std::endl;
}

void	Convert::convertDouble()
{
	d = strtod(value.c_str(), NULL);
	f = static_cast<float>(d);

	if (!IntBound())
	{
		std::cout << "char   : " << "impossible" << std::endl;
		std::cout << "int    : " << "over int bound" << std::endl;
		std::cout << "float  : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
		return ;
	}		
	i = static_cast<int>(d);
	if (i < 33 || i == 127)
		c = "Non displayable";
	else if (i > 127)
		c = "impossible";
	else
		c = static_cast<char>(i);
	std::cout << "char   : " << this->c << std::endl;
	std::cout << "int    : " << this->i << std::endl;
	std::cout << "float  : " << this->f << "f" << std::endl;
	std::cout << "double : " << this->d << std::endl;
}


void	Convert::conversion()
{
	switch (this->type)
	{
		case ('c'):
			convertChar();
			break;
		case ('i'):
			convertInt();
			break;
		case ('f'):
			convertFloat();
			break;
		case ('d'):
			convertDouble();
			break;
		default : 
			throw (NoTypeException());
	}
}




Convert::Convert() {}

Convert::Convert(char type, std::string value)
{
	this->type = type;
	this->value = value;
}

Convert::~Convert()
{
}

const char	*Convert::NoTypeException::what() const throw()
{
	return "no type";
}
