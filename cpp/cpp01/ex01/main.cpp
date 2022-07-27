



#include "Zombie.hpp"

int	main()
{
	int		N;
	Zombie	*z;

	std::cout << "how many Zombies do you want? : ";
	std::cin >> N;

	z = zombieHorde(N, "san");
	for (int i = 0; i < N; i++)
	{
		z[i].announce();
	}
	delete [] z;
	return (0);
}
