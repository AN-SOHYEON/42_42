/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:01:33 by san               #+#    #+#             */
/*   Updated: 2022/08/05 15:01:34 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> 
void	swap(T &a, T &b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> 
T	min(T a, T b)
{
	if (a >= b)
		return (b);
	else 
		return (a);
}

template <typename T> 
T	max(T a, T b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

#endif
