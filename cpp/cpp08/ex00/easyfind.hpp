


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T> 
int	easyfind(T const &t, int i)
{
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), i);
	if (*it == i)
		return (*it);
	std::cout << i << " didnt exist in here" << std::endl;
	return (*it);
}

#endif
