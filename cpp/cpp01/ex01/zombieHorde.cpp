


#include "Zombie.hpp"

// std::string	iToA(int i)
// {

// }

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*z = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		z[i].setName(name);
		// z[i].setName(name + iToA(i));
	}
	return (z);
}