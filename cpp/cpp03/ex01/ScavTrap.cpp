

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->is_keeper = 0;

	std::cout << "Default constructor of scavtrap called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->is_keeper = 0;

	std::cout << "Name constructor of scavtrap called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	this->name = scavTrap.name;
	this->hit_point = scavTrap.hit_point;
	this->energy_point = scavTrap.energy_point;
	this->attack_damage = scavTrap.attack_damage;

	std::cout << "Copy constructor of claptrap called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of scavtrap " << name << " called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavtrap)
{
	this->name = scavtrap.name;
	this->hit_point = scavtrap.hit_point;
	this->energy_point = scavtrap.energy_point;
	this->attack_damage = scavtrap.attack_damage;

	std::cout << "Copy assignment operator of scavtrap called" << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (hit_point == 0 || energy_point == 0)
	{
		std::cout << "\nTrap " << name << " is already DEAD\n" << std::endl;
		return ;
	}
	if (is_keeper == 1)
		std::cout << name << " is already keeper" << std::endl;
	else
	{
		is_keeper = 1;
		std::cout << name << " is GATE KEEPER now!" << std::endl;
	}
}