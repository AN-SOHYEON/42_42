/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:15:22 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:15:25 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const	Animal* meta = new Animal();
		const	Animal* j = new Dog();
		const	Animal* i = new Cat();
		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;


		delete meta;
		delete j;
		delete i;
	}
	{	
		std::cout << "\n\n===============test WRONGver================\n\n" << std::endl;
		std::cout << std::endl;

		const	WrongAnimal	*wrongMeta = new WrongAnimal();
		const	WrongAnimal	*wrongi = new WrongCat();
		const	WrongCat	*wrongCat = new WrongCat();
		std::cout << std::endl;

		std::cout << wrongMeta->getType() << std::endl;
		std::cout << wrongi->getType() << std::endl;
		std::cout << wrongCat->getType() << std::endl;	
		std::cout << std::endl;

		std::cout << "wrongCat says ";
		wrongCat->makeSound();
		std::cout << "wrongi says ";
		wrongi->makeSound();
		std::cout << "wrongAnimal says ";
		wrongMeta->makeSound();
		std::cout << std::endl;

		delete wrongMeta;
		delete wrongi;
		delete wrongCat;
	}
	
	return (0);
}
