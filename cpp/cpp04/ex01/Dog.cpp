
#include "Dog.hpp"

Dog::Dog()
{
	this->type = "DOG";
	this->brain = new Brain("I AM DOG");

	std::cout << "Default constructor of Dog called." << std::endl;
}

Dog::Dog(const Dog &dog)
{
	this->type = dog.getType();
	if (!this->brain)
	{
		delete brain;
	}
	this->brain = new Brain(*dog.getBrain());

	std::cout << "Copy constructor of Dog called" << std::endl;
}

Dog::~Dog()
{
	delete	this->brain;

	std::cout << "Destructor of Dog called" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	this->type = dog.getType();
	this->brain = dog.getBrain();

	std::cout << "Copy assignment operator of Dog called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "I AM DOG.\nMY SOUND IS 멍멍!" << std::endl;
}

void	Dog::printAllBrain() const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << brain->getBrain(i) << std::endl;
	}
}

void	Dog::printBrain(int i) const
{
	std::cout << brain->getBrain(i) << std::endl;
}

void	Dog::setBrain(std::string str, int i)
{
	this->brain->setBrain(str, i);
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}