
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
	
	// system("leaks animal00");
	return (0);
}