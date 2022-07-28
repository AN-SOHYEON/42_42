
#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	frac_bit = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& );

		Fixed&	operator=(const Fixed& );
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};



Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::~Fixed()
{
	std::cout << "Fixed Destructor" << std::endl;
}

Fixed::Fixed(const Fixed& )
{
	
}

Fixed&	Fixed::operator=(const Fixed& )
{
	
}

int	Fixed::getRawBits(void) const
{

}

void	Fixed::setRawBits(int const raw)
{

}