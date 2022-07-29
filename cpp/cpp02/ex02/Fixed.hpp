

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	frac_bit = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& ob);
		Fixed(int num);
		Fixed(float num);
		Fixed&	operator=(const Fixed& a);

		bool operator>(const Fixed &a) const;
		bool operator<(const Fixed &a) const;
		bool operator>=(const Fixed &a) const;
		bool operator<=(const Fixed &a) const;
		bool operator==(const Fixed &a) const;
		bool operator!=(const Fixed &a) const;

		Fixed operator+(const Fixed &a) const;
		Fixed operator-(const Fixed &a) const;
		Fixed operator*(const Fixed &a) const;
		Fixed operator/(const Fixed &a) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		
};

std::ostream &operator<<(std::ostream &stream, const Fixed &value);

#endif