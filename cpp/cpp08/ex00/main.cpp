/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:48:29 by san               #+#    #+#             */
/*   Updated: 2022/08/06 12:48:30 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>
# include <list>

int	main()
{
	std::cout << "================ vector test =================" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		v.push_back(i + 10);
	}
	for (int i = 0; i < 3; i++)
	{
		v.push_back(i + 10);
	}
	std::cout << "vec list" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << "temfunc test" << std::endl;
	std::cout << easyfind(v,11) << std::endl;

	std::cout << "================ list test =================" << std::endl;
	std::list<int> l;
	for (int i = 0; i < 3; i++)
	{
		l.push_back(i + 10);
	}
	for (int i = 0; i < 3; i++)
	{
		l.push_back(i + 10);
	}
	std::cout << "vec list" << std::endl;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "temfunc test" << std::endl;
	std::cout << easyfind(l,11) << std::endl;

	std::cout << "noelement" << std::endl;
	std::cout << easyfind(l,13) << std::endl;
	std::cout << "no element find" << std::endl;
	std::list<int>::iterator t =  std::find(l.begin(), l.end(), 13);
	std::cout << *t << std::endl;

	// system("leaks stl00");
	return (0);
}
