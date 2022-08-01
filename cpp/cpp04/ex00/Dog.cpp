
#include "Dog.hpp"

Dog::Dog()
{
	this->type = "DOG";

	std::cout << "Default constructor of Dog called." << std::endl;
}

Dog::Dog(const Dog &dog)
{
	this->type = dog.getType();

	std::cout << "Copy constructor of Dog called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	this->type = dog.getType();

	std::cout << "Copy assignment operator of Dog called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "I AM DOG.\nMY SOUND IS 멍멍!" << std::endl;
}