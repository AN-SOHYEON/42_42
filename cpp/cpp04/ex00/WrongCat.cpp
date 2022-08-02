/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:15:07 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:15:08 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";

	std::cout << "Default constructor of WrongCat called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &Wrongcat)
{
	this->type = Wrongcat.getType();

	std::cout << "Copy constructor of WrongCat called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &Wrongcat)
{
	this->type = Wrongcat.getType();

	std::cout << "Copy assignment operator of WrongCat called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "I AM CAT.\nMY SOUND IS 야옹!" << std::endl;
}
