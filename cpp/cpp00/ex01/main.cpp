/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:54:14 by san               #+#    #+#             */
/*   Updated: 2022/07/28 13:54:32 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	ft_exit()
{
	std::cout << "delete AWESOME PHONEBOOK" << std::endl;
}

std::string	low_to_up(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}

int	commandType(std::string comm)
{
	int	i;

	i = 0;
	while (comm[i])
	{
		comm[i] = toupper(comm[i]);
		i++;
	}
	if (comm == "ADD" || comm == "1")
		return (1);
	else if (comm == "SEARCH" || comm == "2")
		return (2);
	else if (comm == "EXIT" || comm == "3")
		return (3);
	else
		return (4);
}

int main (void)
{
	PhoneBook pb;
	std::string comm;
	int			command;

	while (1)
	{
		std::cout << "~~AWESOME PHONEBOOK~~" << std::endl;
		std::cout << " put your command |  1.ADD  2.SEARCH  3.EXIT " << std::endl;

		getline(std::cin, comm, '\n');
		command = commandType(comm);

		if (command == 1)
		{
			pb.addContact();
		}
		else if(command == 2)
		{
			pb.searchPhoneBook();
		}
		else if (command == 3)
		{
			break;
		}
		else
		{
			std::cout << "cannot found command : " << comm << std::endl;
		}	
	}
	return (0);
}
