



# include "easyfind.hpp"
# include <vector>
# include <list>
# include <map>

int	main()
{
	std::cout << "================ vector test =================" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		v.push_back(i + 10);
	}
	for (int i = 0; i < 3; i++)
	{
		v.push_back(i + 10);
	}
	std::cout << "vec list" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << "temfunc test" << std::endl;
	std::cout << easyfind(v,11) << std::endl;
	



	return (0);
}