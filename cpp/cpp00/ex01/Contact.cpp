



 #include "main.hpp"

Contact::Contact(){} 

Contact::~Contact()
{
	std::cout << "delete contact" << std::endl;
} 

void	Contact::show_all()
{
	std::cout << std::setw(15) << std::left << "first name " << ": " << name_f << std::endl;
	std::cout << std::setw(15) << std::left << "last name " << ": " << name_l << std::endl;
	std::cout << std::setw(15) << std::left << "nickname " << ": " << nickname << std::endl;
	std::cout << std::setw(15) << std::left << "phonenumber " << ": " << number << std::endl;
	std::cout << std::setw(15) << std::left << "darkest secret " << ": " << secret << std::endl;
	std::cout << std::endl;
}

std::string	setStrLen10(std::string str)
{
	if (str.length() >= 10)
	{
		str.resize(9);
		str.resize(10, '.');
	}
	return (str);
}

void	Contact::show_for_search()
{
	std::cout << std::setw(10) << std::left << setStrLen10(name_f) << "|" << std::setw(10) << std::left << setStrLen10(name_l) << "|" << std::setw(10) << std::left << setStrLen10(nickname) << std::endl;
}

void	Contact::set_all()
{
	std::cout << std::setw(15) << std::left << "first name " << ": ";
	std::cin >> name_f;

	std::cout << std::setw(15) << std::left << "last name " << ": ";
	std::cin >> name_l;

	std::cout << std::setw(15) << std::left << "nickname " << ": ";
	std::cin >> nickname;

	std::cout << std::setw(15) << std::left << "phonenumber " << ": ";
	std::cin >> number;

	std::cout << std::setw(15) << std::left << "darkest secret " << ": ";
	std::cin >> secret;
}

