

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
	Bureaucrat san148("SAN148", 148);
	
	{

		std::cout << "================= no exception ==================" << std::endl;

		try {

			std::cout << "##make shrubbery -> sign -> execute" << std::endl;
			ShrubberyCreationForm	s1("shrubbery");
			std::cout << s1 << std::endl;

			san140.signForm(s1);
			std::cout << s1 << std::endl;

			san100.executeForm(s1);
			std::cout << std::endl;

			std::cout << "##make roborForm -> sign -> execute" << std::endl;
			RobotomyRequestForm	r1("robot");
			std::cout << r1 << std::endl;

			san30.signForm(r1);
			std::cout << r1 << std::endl;

			san13.executeForm(r1);
			std::cout << std::endl;

			std::cout << "##make presidentForm -> sign -> execute" << std::endl;
			PresidentialPardonForm	p1("presidentialPardon");
			std::cout << p1 << std::endl;

			san13.signForm(p1);
			std::cout << p1 << std::endl;

			san2.executeForm(p1);
			std::cout << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= over(low) level try to execute form ==================" << std::endl;

		try {

			std::cout << "##make shrubbery -> sign -> execute" << std::endl;
			ShrubberyCreationForm	s1("shrubbery");
			std::cout << s1 << std::endl;

			san140.signForm(s1);
			std::cout << s1 << std::endl;

			san140.executeForm(s1);
			std::cout << std::endl;

			std::cout << "##make roborForm -> sign -> execute" << std::endl;
			RobotomyRequestForm	r1("robot");
			std::cout << r1 << std::endl;

			san30.signForm(r1);
			std::cout << r1 << std::endl;

			san50.executeForm(r1);
			std::cout << std::endl;

			std::cout << "##make presidentForm -> sign -> execute" << std::endl;
			PresidentialPardonForm	p1("presidentialPardon");
			std::cout << p1 << std::endl;

			san13.signForm(p1);
			std::cout << p1 << std::endl;

			san13.executeForm(p1);
			std::cout << std::endl;
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= try to execte notsigned form ==================" << std::endl;
		try {

			std::cout << "##make shrubbery -> sign -> execute" << std::endl;
			ShrubberyCreationForm	s1("shrubbery");
			std::cout << s1 << std::endl;

			san100.executeForm(s1);
			std::cout << std::endl;

			std::cout << "##make roborForm -> sign -> execute" << std::endl;
			RobotomyRequestForm	r1("robot");
			std::cout << r1 << std::endl;

			san13.executeForm(r1);
			std::cout << std::endl;

			std::cout << "##make presidentForm -> sign -> execute" << std::endl;
			PresidentialPardonForm	p1("presidentialPardon");
			std::cout << p1 << std::endl;

			san2.executeForm(p1);
			std::cout << std::endl;
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}