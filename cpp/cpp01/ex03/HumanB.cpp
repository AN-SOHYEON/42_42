

#include "HumanB.hpp"

HumanB::HumanB(){}

HumanB::HumanB(std::string name, Weapon &weapon)
    : name(name), weapon(&weapon) {
}

HumanB::~HumanB()
{
	std::cout << name << "says GOODBYE" << std::endl;
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