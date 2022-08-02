/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:24:02 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:24:07 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	{
		std::cout << "================= check abstract class cant make instance =====================" << std::endl;

		Dog *dog = new Dog();
		Cat *cat = new Cat();
		// Animal animal();
		std::cout << std::endl;

		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		std::cout << std::endl;

		delete dog;
		delete cat;
	}
	return (0);
}
