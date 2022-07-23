


#include <iostream>

class	Megaphone 
{
public:
	void	low_to_up(char *text);
	void	loud(char *text);
};

void	Megaphone::low_to_up(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		text[i] = toupper(text[i]);
		i++;
	}
}

void	Megaphone::loud(char *text)
{
	low_to_up(text);
	std::cout << text;
}


int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		Megaphone	mega;
		while (i < ac)
		{
			mega.loud(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}