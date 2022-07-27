
#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "string address : " << &brain << std::endl;
	std::cout << "string address held by ptr : " << stringPTR << std::endl;
	std::cout << "string address held by ref : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "string value : " << brain << std::endl;
	std::cout << "string value pointed to by ptr : " << *stringPTR << std::endl;
	std::cout << "string value pointed to by ref : " << stringREF << std::endl;
	return (0);
}