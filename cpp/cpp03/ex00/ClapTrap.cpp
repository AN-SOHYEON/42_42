

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "noname";
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;

	std::cout << "Default constructor of claptrap called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;

	std::cout << "Name constructor of claptrap called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	this->name = claptrap.name;
	this->hit_point = claptrap.hit_point;
	this->energy_point = claptrap.energy_point;
	this->attack_damage = claptrap.attack_damage;

	std::cout << "Copy constructor of claptrap called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor of claptrap called" << std::endl; }

ClapTrap	&ClapTrap::operator=(const ClapTrap &claptrap)
{
	this->name = claptrap.name;
	this->hit_point = claptrap.hit_point;
	this->energy_point = claptrap.energy_point;
	this->attack_damage = claptrap.attack_damage;

	std::cout << "Copy assignment operator of claptrap called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (hit_point == 0 || energy_point == 0)
	{
		std::cout << "\nClapTrap " << name << " is already DEAD\n" << std::endl;
		return ;
	}
	energy_point--;
	std::cout << "\nClapTrap " << name << " attacks " << target <<  std::endl;
	std::cout << target << " gets " << attack_damage << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << name << "'s energy is " << energy_point << "points..\n"<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point == 0)
	{
		std::cout << "\nClapTrap " << name << " is already DEAD\n" << std::endl;
	}
	else if (hit_point <= amount)
	{
		hit_point = 0;
		std::cout << "\nClapTrap " << name << " takes " << amount
				<< " points of damege" << std::endl;
		std::cout << name << "'s hit point is " << hit_point << " now!" << std::endl;
		std::cout << "ClapTrap " << name << " die now!!!\n" << std::endl;
	}
	else
	{
		hit_point = hit_point - amount;
		std::cout << "\nClapTrap " << name << " takes " << amount
				<< " points of damege" << std::endl;
		std::cout << name << "'s hit point is " << hit_point << " now!\n" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point == 0 || energy_point == 0)
	{
		std::cout << "\nClapTrap " << name << " is already DEAD\n" << std::endl;
		return ;
	}
	energy_point--;
	hit_point = hit_point + amount;
	std::cout << "\nClapTrap " << name << " be repaired!" << std::endl;
	std::cout << name << "'s hit_point is " << hit_point << " now!" << std::endl;
	std::cout << "ClapTrap " << name << "'s energy is " << energy_point << "points..\n"<< std::endl;
}