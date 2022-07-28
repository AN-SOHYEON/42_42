


#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*z = new Zombie[N];
	if(!z)
		return (NULL);

	for (int i = 0; i < N; i++)
	{
		z[i].setName(name);
	}
	return (z);
}