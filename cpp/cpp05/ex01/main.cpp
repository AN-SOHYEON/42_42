/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:12:10 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:12:12 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "================= no exception ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 13);
			Form	f("sanForm", false, 20, 20);

			std::cout << b << std::endl;

			std::cout << "san try to sign" << std::endl;
			b.signForm(f);
			std::cout << std::endl;

			std::cout << "after execute san.signform(form)" << std::endl;
			if (f.getIsSigned())
				std::cout << "true" << std::endl;
			else
				std::cout << "not change" << std::endl;
			std::cout << f << std::endl;
			std::cout << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= over(high) level in form ==================" << std::endl;

		try {

			Form	f("sanForm", false, 0, 1);
			
			std::cout << f << std::endl;
			std::cout << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= over(low) level in form ==================" << std::endl;
		try {

			Form	f("sanForm", false, 2, 189);

			std::cout << f << std::endl;
			std::cout << std::endl;

			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= try signed by invalid level ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 45);
			Form	f("sanForm", false, 40, 50);

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			
			b.signForm(f);

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
