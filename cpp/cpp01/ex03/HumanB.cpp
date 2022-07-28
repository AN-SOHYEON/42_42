

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