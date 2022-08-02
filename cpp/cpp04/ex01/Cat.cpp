/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:21:51 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:21:52 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain("I AM CAT");

	std::cout << "Default constructor of Cat called." << std::endl;
}

Cat::Cat(const Cat &cat) : Animal()
{
	this->type = cat.getType();
	this->brain = new Brain(*cat.getBrain());

	std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat::~Cat()
{
	delete	this->brain;

	std::cout << "Destructor of Cat called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	this->type = cat.getType();
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain(*cat.getBrain());

	std::cout << "Copy assignment operator of Cat called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "I AM CAT.\nMY SOUND IS 야옹!" << std::endl;
}

void	Cat::printAllBrain() const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << brain->getBrain(i) << std::endl;
	}
}

void	Cat::printBrain(int i) const
{
	std::cout << brain->getBrain(i) << std::endl;
}

void	Cat::setBrain(std::string str, int i)
{
	this->brain->setBrain(str, i);
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}
