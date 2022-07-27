



#include "Zombie.hpp"

int main()
{
	Zombie	*z = newZombie("san1");
	z->announce();
	randomChump("san2");
	delete z;
	return (0);
}