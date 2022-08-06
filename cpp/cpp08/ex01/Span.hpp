/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:21:19 by san               #+#    #+#             */
/*   Updated: 2022/08/06 14:21:20 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		template <typename T> 
		void	addNumber(T begin, T end);
		int		longestSpan();
		int		shortestSpan();

	class	OverVectorLength : public std::exception
	{
		public :
			const char	*what() const throw();
	};
};

template <typename T> 
void	Span::addNumber(T begin, T end)
{
	while (begin != end)
	{	
		if (len == 0)
		{
			v.push_back(*begin);
			len++;
			begin++;
		}
		if (len == max)
			throw (OverVectorLength());
		v.push_back(*begin);
		len++;
		if (*begin > v[len - 2])
			v_span.push_back(*begin - v[len - 2]);
		else
			v_span.push_back(v[len - 2] - *begin);
		begin++;
	}
}

#endif
