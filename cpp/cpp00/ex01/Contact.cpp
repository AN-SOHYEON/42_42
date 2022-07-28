/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:56:15 by san               #+#    #+#             */
/*   Updated: 2022/07/28 13:56:27 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "main.hpp"

Contact::Contact(){} 

Contact::~Contact()
{
	std::cout << "delete contact" << std::endl;
} 

void	Contact::show_all()
{
	std::cout << std::setw(15) << std::right << "first name " << ": " << name_f << std::endl;
	std::cout << std::setw(15) << std::right << "last name " << ": " << name_l << std::endl;
	std::cout << std::setw(15) << std::right << "nickname " << ": " << nickname << std::endl;
	std::cout << std::setw(15) << std::right << "phonenumber " << ": " << number << std::endl;
	std::cout << std::setw(15) << std::right << "darkest secret " << ": " << secret << std::endl;
	std::cout << std::endl;
}

std::string	setStrLen10(std::string str)
{
	if (str.length() >= 10)
	{
		str = str.substr(0, 9) + '.';
	}
	return (str);
}

void	Contact::show_for_search()
{
	std::cout << std::setw(10) << std::right << setStrLen10(name_f) << "|" << std::setw(10) << std::right << setStrLen10(name_l) << "|" << std::setw(10) << std::right << setStrLen10(nickname) << std::endl;
}

void	Contact::set_all()
{
	std::cout << std::setw(15) << std::right << "first name " << ": ";
	getline(std::cin, name_f, '\n');
	
	std::cout << std::setw(15) << std::right << "last name " << ": ";
	getline(std::cin, name_l, '\n');

	std::cout << std::setw(15) << std::right << "nickname " << ": ";
	getline(std::cin, nickname, '\n');

	std::cout << std::setw(15) << std::right << "phonenumber " << ": ";
	getline(std::cin, number, '\n');

	std::cout << std::setw(15) << std::right << "darkest secret " << ": ";
	getline(std::cin, secret, '\n');
}

