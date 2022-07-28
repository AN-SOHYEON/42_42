



#include "Zombie.hpp"

int	main(void)
{
	int		N;
	Zombie	*z;

	std::cout << "how many Zombies do you want? : ";
	std::cin >> N;
	if (N < 1)
	{
		std::cout << "wrong input | N can be 1 ~ " << std::endl;
		return (0);
	}

	z = zombieHorde(N, "san");
	if (!z)
		return (1);
	for (int i = 0; i < N; i++)
	{
		z[i].announce();
	}
	delete [] z;
	return (0);
}
