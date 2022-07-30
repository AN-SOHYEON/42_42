


#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap san("SAN-2");
	
	san.attack("SAN-3");

	san.takeDamage(5);
	san.beRepaired(1);

	san.takeDamage(7);

	san.beRepaired(9);

	return (0);
}