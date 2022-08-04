


#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> 
void	iter(T *arr, int len, void f(T const &t))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	ptl(T const &t)
{
	std::cout << t << std::endl;
}

#endif