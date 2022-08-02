/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:28:06 by san               #+#    #+#             */
/*   Updated: 2022/08/02 15:28:08 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap san2("SAN-2");
	ScavTrap san3("SAN-3");	

	san2.attack("SAN-3");
	san3.takeDamage(20);

	san3.beRepaired(10);

	san2.guardGate();

	san3.takeDamage(120);

	san2.guardGate();

	san3.beRepaired(9);

	return (0);
}
