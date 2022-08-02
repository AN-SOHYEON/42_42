/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:21:37 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:21:38 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "WHO AM I";
	}
	std::cout << "Default constructor of Brain called." << std::endl;
}

Brain::Brain(std::string str)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = str;
	}
	std::cout << "setString constructor of Brain called." << std::endl;	
}

Brain::Brain(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.getBrain(i);
	}
	std::cout << "Copy constructor of Brain called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

Brain	&Brain::operator=(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.getBrain(i);
	}
	std::cout << "Copy assignment operator of Brain called" << std::endl;
	return (*this);
}

void	Brain::setBrain(std::string str, int i)
{
	this->ideas[i] = str;
}

void	Brain::setAllBrain(std::string str)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = str;
	}
}

std::string	Brain::getBrain(int i) const
{
	return (this->ideas[i]);
}
