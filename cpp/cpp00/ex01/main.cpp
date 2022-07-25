




#include "main.hpp"

void	ft_exit()
{
	
}


int main ()
{
	PhoneBook pb ;
	int		i;
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
			/*지정되지 얺은 명령어가 들어왔을 떄  code */
		}
		
	}
	if (command.compare("EXIT") == 0)
		ft_exit();
	return (0);
}