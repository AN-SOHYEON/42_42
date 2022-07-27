



#include "Zombie.hpp"

extern void	randomChump(std::string name);
extern Zombie  *newZombie(std::string name);

int main()
{
	Zombie	*z = newZombie("san1");
	z->announce();
	
	randomChump("san2");

	delete z;

	return (0);
}