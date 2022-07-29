/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:41:55 by san               #+#    #+#             */
/*   Updated: 2022/07/29 16:41:57 by san              ###   ########.fr       */
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

Fixed::Fixed(const Fixed& ob)
{
	// *this = ob;
	std::cout << "Copy constructor called" << std::endl;
	*this = ob;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = num * (1 << frac_bit);
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = static_cast<int>(roundf(num * (1 << frac_bit)));
}

Fixed	&Fixed::operator=(const Fixed& ob)
{
	// this->setRawBits(ob.getRawBits());
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(ob.getRawBits());
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

std::ostream &operator<<(std::ostream &stream, const Fixed &value)
{
	stream << value.toFloat();
	return (stream);
}


//순서에 주의 
