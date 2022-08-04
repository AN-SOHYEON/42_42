

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "=====================================================" << std::endl;

	Intern	i;
	Form	*a, *b, *c, *d;
	try {
		a = i.makeForm("ROBOT", "robot");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b = i.makeForm("PRESIDENT", "president");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		c = i.makeForm("SHRUBBERY", "shrubbery");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		d = i.makeForm("hoho", "hoho");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete a;
	delete b;
	delete c;
	
	return (0);
}