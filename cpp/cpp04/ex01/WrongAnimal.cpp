
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "wrongAnimal";

	std::cout << "Default constructor of WrongAnimal called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;

	std::cout << "Type constructor of WrongAnimal called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	this->type = wrongAnimal.getType();

	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	this->type = wrongAnimal.getType();

	std::cout << "Copy assignment operator of WrongAnimal called" << std::endl;
	return (*this);
}

std::string		WrongAnimal::getType() const
{
	return (this->type);
}


void	WrongAnimal::makeSound() const
{
	std::cout << "... I don't know my sound yet.. ㅠㅡㅜ" << std::endl;
}