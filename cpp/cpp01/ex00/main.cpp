



#include "Zombie.hpp"

int main(void)
{
	Zombie	*z = newZombie("san1");
	z->announce();
	randomChump("san2");
	delete z;
	return (0);
}