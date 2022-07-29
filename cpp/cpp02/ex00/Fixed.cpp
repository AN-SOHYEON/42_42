
#include "Fixed.hpp"

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

Fixed	&Fixed::operator=(const Fixed& ob)
{
	// this->setRawBits(ob.getRawBits());
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(ob.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}


//순서에 주의 