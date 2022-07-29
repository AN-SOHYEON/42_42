/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:46:19 by san               #+#    #+#             */
/*   Updated: 2022/07/29 12:46:20 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
