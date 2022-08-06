/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:48:26 by san               #+#    #+#             */
/*   Updated: 2022/08/06 12:48:26 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <algorithm>

template <typename T> 
int	easyfind(T &t, int i)
{
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), i);
	if (*it == i)
		return (*it);
	std::cout << i << " didnt exist in here" << std::endl;
	return (*it);
}

#endif
