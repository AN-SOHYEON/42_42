

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "================= no exception ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 13);

			std::cout << b << std::endl;
			
			b.downGrade();
			std::cout << b << std::endl;

			b.upGrade();
			std::cout << b << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= over(high) level in form ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 0);

			std::cout << b << std::endl;
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= over(low) level in form ==================" << std::endl;
		try {

			Bureaucrat b("SAN", 180);

			std::cout << b << std::endl;
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= try signed by invalid level ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 2);

			std::cout << b << std::endl;
			
			b.upGrade();
			b.upGrade();
			b.upGrade();
			std::cout << b << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "================= try executed by invalid level ==================" << std::endl;

		try {

			Bureaucrat b("SAN", 148);

			std::cout << b << std::endl;
			
			b.downGrade();
			b.downGrade();
			b.downGrade();
			b.downGrade();
			std::cout << b << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}