
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const	Animal* meta = new Animal();
		const	Animal* j = new Dog();
		const	Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{	
		std::cout << "\n\n===============test WRONGver================\n\n" << std::endl;

		const	WrongAnimal	*wrongMeta = new WrongAnimal();
		const	WrongAnimal	*wrongi = new WrongCat();
		const	WrongCat	*wrongCat = new WrongCat();

		std::cout << wrongMeta->getType() << std::endl;
		std::cout << wrongi->getType() << std::endl;
		std::cout << wrongCat->getType() << std::endl;	

		std::cout << "wrongCat says ";
		wrongCat->makeSound();
		std::cout << "wrongi says ";
		wrongi->makeSound();
		std::cout << "wrongAnimal says ";
		wrongMeta->makeSound();

		delete wrongMeta;
		delete wrongi;
		delete wrongCat;
	}
	
	// system("leaks animal00");
	return (0);
}