

#include "Span.hpp"

Span::Span()
{
	len = 0;
}

Span::Span(int max)
{
	this->len = 0;
	this->max = max;
}

Span::~Span(){}

Span::Span(const Span &span)
{
	(void)span;
}

const Span	&Span::operator=(const Span &span)
{
	(void)span;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (len == max)
		throw (OverVectorLength());
	v.push_back(n);
	len++;
	if (n > v[len - 2])
		v_span.push_back(n - v[len - 2]);
	else
		v_span.push_back(v[len - 2] - n);
}

int		Span::longestSpan()
{
	return (*max_element(v_span.begin(), v_span.end()));
}

int		Span::shortestSpan()
{
	return (*min_element(v_span.begin(), v_span.end()));
}

const char	*Span::OverVectorLength::what() const throw()
{
	return "Over MAX Length, so cant add Number in here";
}