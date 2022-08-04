

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//  sign 145, exec 137
//  sign 72, exec 45
//  sign 25, exec 5

int	main()
{
	Bureaucrat san2("SAN2", 2);
	Bureaucrat san13("SAN13", 13);
	Bureaucrat san30("SAN30", 30);
	Bureaucrat san50("SAN50", 50);
	Bureaucrat san100("SAN100", 100);
	Bureaucrat san140("SAN140", 140);
	Bureaucrat san100("SAN148", 148);
	
	{

		std::cout << "================= no exception ==================" << std::endl;

		try {



		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= over(low) level try to execute form ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 0);


			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= try to execte notsigned form ==================" << std::endl;
		try {

			Bureaucrat b("SAN", 180);

			std::cout << b << std::endl;
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}