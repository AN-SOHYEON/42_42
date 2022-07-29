

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
		Fixed(const Fixed& );

		Fixed&	operator=(const Fixed& a);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif