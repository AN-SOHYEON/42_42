/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:03 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:22:04 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "DOG";
	this->brain = new Brain("I AM DOG");

	std::cout << "Default constructor of Dog called." << std::endl;
}

Dog::Dog(const Dog &dog) : Animal()
{
	this->type = dog.getType();
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
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain(*dog.getBrain());

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
