/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:16:45 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:16:51 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "=====================================================" << std::endl;

	Intern	i;
	Form	*a, *b, *c, *d;
	try {
		a = i.makeForm("ROBOT", "robot");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b = i.makeForm("PRESIDENT", "president");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		c = i.makeForm("SHRUBBERY", "shrubbery");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		d = i.makeForm("hoho", "hoho");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete a;
	delete b;
	delete c;
	
	return (0);
}
