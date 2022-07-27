




#include "main.hpp"

void	ft_exit()
{
	std::cout << "delete AWESOME PHONEBOOK" << std::endl;
}


int main ()
{
	PhoneBook pb;
	// int		i;
	std::string command;

	while (1)
	{
		std::cout << "[AWESOME PHONEBOOK] | put your command |  1.ADD  2.SEARCH  3.EXIT " << std::endl;
		std::cin >> command;
		if (command == "ADD" || command == "1")
		{
			pb.ft_add();
		}
		else if(command == "SEARCH" || command == "2")
		{
			pb.ft_search();
		}
		else if (command == "EXIT" || command == "3")
		{
			break;
		}
		else
		{
			std::cout << "cannot found command : " << command << std::endl;
		}
		
	}
	if (command == "EXIT" || command == "3")
		ft_exit();
	return (0);
}