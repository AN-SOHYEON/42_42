/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:40:47 by san               #+#    #+#             */
/*   Updated: 2022/07/29 16:40:57 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//const int Fixed::frac_bit = 8;

Fixed::Fixed()
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	this -> fixed_point = fixed.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
	this->fixed_point = num * (1 << frac_bit);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	this->fixed_point = static_cast<int>(roundf(num * (1 << frac_bit)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed& fixed)
{
	this->setRawBits(fixed.getRawBits());
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float	Fixed::toFloat( void ) const
{
	float	f;

	f = static_cast<float>(this->getRawBits()) / (1 << frac_bit);
	return (f);
}

int		Fixed::toInt( void ) const
{
	int	i;

	i = static_cast<int>(roundf(this->getRawBits() / (1 << frac_bit)));
	return (i);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &value)
{
	stream << value.toFloat();
	return (stream);
}
