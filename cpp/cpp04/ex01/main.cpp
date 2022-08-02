/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:24 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:22:25 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	{
		std::cout << "================= check leaks =====================" << std::endl;

		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << std::endl;

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << std::endl;

		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		std::cout << std::endl;

		delete dog;//should not create a leak
		delete cat;
	}

	{
		std::cout << "\n================= check subject arr =====================" << std::endl;
		
		int len = 10;
		Animal	*arr[len];
		for (int i = 0; i < 5; i++)
		{
			arr[i] = new Dog();
			arr[i + 5] = new Cat();
		}
		std::cout << std::endl;

		for (int i = 0; i < 10; i++)
		{
			delete arr[i];
		}
		std::cout << std::endl;

	}

	{
		std::cout << "\n================= check deep copy =====================" << std::endl;
		
		Cat cat;
		std::cout << std::endl;

		cat.printAllBrain(); //will output the cat sound!
		std::cout << std::endl;

		Cat testcat(cat);
		cat.setBrain("cat change arr2", 2);
		cat.printBrain(2);
		testcat.printBrain(2);
		std::cout << std::endl;

	}
	return (0);
}
