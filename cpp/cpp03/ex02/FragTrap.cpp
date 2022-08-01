

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;

	std::cout << "Default constructor of Fragtrap called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;

	std::cout << "Name constructor of Fragtrap called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	this->name = fragTrap.name;
	this->hit_point = fragTrap.hit_point;
	this->energy_point = fragTrap.energy_point;
	this->attack_damage = fragTrap.attack_damage;

	std::cout << "Copy constructor of Fragtrap called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of Fragtrap " << name << " called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &fragtrap)
{
	this->name = fragtrap.name;
	this->hit_point = fragtrap.hit_point;
	this->energy_point = fragtrap.energy_point;
	this->attack_damage = fragtrap.attack_damage;

	std::cout << "Copy assignment operator of Fragtrap called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (hit_point == 0 || energy_point == 0)
	{
		std::cout << "\nTrap " << name << " is already DEAD\n" << std::endl;
		return ;
	}
	std::cout << name << " 의 하이파이브를 받아라 ㅎ" << std::endl;
}