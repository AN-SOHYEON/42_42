
#include "Animal.hpp"

Animal::Animal()
{
	this->type = "animal";

	std::cout << "Default constructor of Animal called." << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;

	std::cout << "Type constructor of Animal called." << std::endl;
}

Animal::Animal(const Animal &animal)
{
	this->type = animal.getType();

	std::cout << "Copy constructor of Animal called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called" << std::endl;
}

Animal	&Animal::operator=(const Animal &animal)
{
	this->type = animal.getType();

	std::cout << "Copy assignment operator of Animal called" << std::endl;
	return (*this);
}

std::string		Animal::getType() const
{
	return (this->type);
}


void	Animal::makeSound() const
{
	std::cout << "... I don't know my sound yet.. ㅠㅡㅜ" << std::endl;
}