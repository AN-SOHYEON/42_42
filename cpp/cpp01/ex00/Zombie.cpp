

#include "Zombie.hpp"

// #include <iostream>
// #include <string>

// class	Zombie
// {
// 	private:
// 		std::string name;
// 	public:
// 		Zombie(){};
// 		~Zombie(){};
// 		void	setName(std::string);
// 		void	announce(void);
// }

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << "GoodBye... " << name << " die again...," << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

