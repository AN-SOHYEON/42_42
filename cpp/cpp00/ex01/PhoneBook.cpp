

#include <iostream>


class	Contact
{
private:
	std::string name_f;
	std::string name_l;
	std::string nickname;
	std::string number;
	std::string secret;
public:
	Contact(){};
	void	show();
	void	set();
};





int main ()
{
	Contact pb[8];
	int		i;
	std::string command;

	while (command.compare("EXIT") != 0)
	{
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{

		}
		else if(command.compare("SEARCH"))
		{

		}
		else
		{
			/*지정되지 얺은 명령어가 들어왔을 떄  code */
		}
		
	}

}