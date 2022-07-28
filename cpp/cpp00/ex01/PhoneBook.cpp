/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:57:59 by san               #+#    #+#             */
/*   Updated: 2022/07/28 13:58:04 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook()
{
	old_contact = 0;
	is_max = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "GoodBye AWESOME PHONEBOOK" << std::endl;
}

void	PhoneBook::get_contact(int index)
{
	pb[index - 1].show_all();
}

Contact	*PhoneBook::addContact()
{
	pb[old_contact].set_all();
	old_contact = (old_contact + 1) % 8;
	if (is_max < 8)
		is_max++;
	return (pb);
}

void	PhoneBook::searchPhoneBook()
{
	int	i;
	int	index;

	std::cout << std::setw(10) << std::right << "index" << "|" << std::setw(10) << std::right << "firstname" << "|" << std::setw(10) << std::right << "lastname" << "|" << std::setw(10) << std::right << "nickname" << std::endl;
	i = 0;
	while (i < is_max)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		pb[i].show_for_search();
		i++;
	}
	while (1)
	{
		std::cout << "choose index : ";	
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "you can choose 1 to 8" << std::endl;
			continue;
		}
		if (index > 0 && index < 9)
		{
			std::cin.ignore(1000, '\n');
			break;
		}
		std::cout << "you can choose 1 to 8" << std::endl;
	}
	pb[index - 1].show_all();
}
