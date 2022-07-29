/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:48:23 by san               #+#    #+#             */
/*   Updated: 2022/07/29 12:48:25 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	std::cout << name << " says GOODBYE" << std::endl;
}

void	HumanB::attack()
{
	if (weapon == NULL)
	{
		std::cout << name << " doesnt have weapon " << std::endl;
	}
	else
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
