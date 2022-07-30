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

const int Fixed::frac_bit = 8;

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& fixed)
{
	this -> fixed_point = fixed.getRawBits();
}

Fixed::Fixed(int num)
{
	this->fixed_point = num * (1 << frac_bit);
}

Fixed::Fixed(float num)
{
	this->fixed_point = static_cast<int>(roundf(num * (1 << frac_bit)));
}

Fixed	&Fixed::operator=(const Fixed& ob)
{
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

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	Fixed	tmp(this->toFloat() + fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	Fixed	tmp(this->toFloat() - fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	Fixed	tmp(this->toFloat() * fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	if (fixed.getRawBits() == 0)
	{
		std::cout << "under 0 cant divide number" << std::endl;
		exit(1);
	}
	Fixed	tmp(this->toFloat() / fixed.toFloat());
	return (tmp);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	&Fixed::operator++()
{
	fixed_point = toInt() + 1;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	fixed_point = toInt() - 1;
	return (*this);
}

Fixed	Fixed::operator++(int i)
{
	Fixed	tmp = *this;

	i = 1;
	// this->fixed_point = this->toInt() + i;
	this->fixed_point = this->fixed_point + i;
	return (tmp);
}

Fixed	Fixed::operator--(int i)
{
	Fixed	tmp = *this;

	i = 1;
	// fixed_point = toInt() - i;
	this->fixed_point = this->fixed_point - i;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	return (f2);
}
