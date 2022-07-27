




#include "main.hpp"

void	ft_exit()
{
	std::cout << "exit" << std::endl;
}


int main ()
{
	PhoneBook pb ;
	// int		i;
	std::string command;

	while (command.compare("EXIT") != 0)
	{
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			pb.ft_add();
		}
		else if(command.compare("SEARCH"))
		{
			pb.ft_search();
		}
		else
		{
			std::cout << "cannot found command : " << command << std::endl;
		}
		
	}
	if (command.compare("EXIT") == 0)
		ft_exit();
	return (0);
}