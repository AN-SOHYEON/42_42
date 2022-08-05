



#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		std::vector<int>	v;
		std::vector<int>	v_span;
		int					len;
		int					max;
		
	public:
		Span();
		Span(int max);
		~Span();
		Span(const Span &span);
		const Span	&operator=(const Span &span);

		void	addNumber(int n);
		int		longestSpan();
		int		shortestSpan();

	class	OverVectorLength : public std::exception
	{
		public :
			const char	*what() const throw();
	};
};



#endif
