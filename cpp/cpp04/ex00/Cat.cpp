
#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";

	std::cout << "Default constructor of Cat called." << std::endl;
}

Cat::Cat(const Cat &cat)
{
	this->type = cat.getType();

	std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	this->type = cat.getType();

	std::cout << "Copy assignment operator of Cat called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "I AM CAT.\nMY SOUND IS 야옹!" << std::endl;
}