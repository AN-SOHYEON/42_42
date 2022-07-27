


#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void	setName(std::string);
		void	announce(void);
};
