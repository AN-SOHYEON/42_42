/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:27:24 by san               #+#    #+#             */
/*   Updated: 2022/08/02 15:27:27 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap san("SAN-2");
	
	san.attack("SAN-3");

	san.takeDamage(5);
	san.beRepaired(1);

	san.takeDamage(7);

	san.beRepaired(9);

	return (0);
}
