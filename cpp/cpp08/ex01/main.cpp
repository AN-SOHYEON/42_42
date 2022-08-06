/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:21:24 by san               #+#    #+#             */
/*   Updated: 2022/08/06 14:21:25 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
# include <cstdlib>
# include <ctime>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "================ 10000 test =================" << std::endl;

	srand(time(NULL));
	Span ss = Span(10500);
	ss.addNumber(80000);
	ss.addNumber(20000);
	for (int i = 0; i < 10498; i++)
	{
		ss.addNumber(rand() % 10500);
	}
	std::cout << "================ span func test =================" << std::endl;
	std::cout << ss.shortestSpan() << std::endl;
	std::cout << ss.longestSpan() << std::endl;
	std::cout << "================ span excep test =================" << std::endl;
	try
	{
		ss.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "================ iterator test =================" << std::endl;

	srand(time(NULL));
	Span ii = Span(10500);
	
	std::vector<int> v;
	v.push_back(80000);
	v.push_back(20000);
	for (int i = 0; i < 10498; i++)
	{
		v.push_back(rand() % 10500);
	}
	ii.addNumber(v.begin(), v.end());
	std::cout << "================ span func test =================" << std::endl;
	std::cout << ii.shortestSpan() << std::endl;
	std::cout << ii.longestSpan() << std::endl;


	// system("leaks stl01");
	return (0);
}
