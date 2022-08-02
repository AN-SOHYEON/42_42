/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:29:14 by san               #+#    #+#             */
/*   Updated: 2022/08/02 15:29:15 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap san2("SAN-2");
	FragTrap san3("SAN-3");	

	san3.highFivesGuys();

	san2.attack("SAN-3");
	san3.takeDamage(20);

	san3.beRepaired(10);

	san3.attack("SAN-2");
	san2.takeDamage(30);

	san2.guardGate();

	san3.takeDamage(120);

	san2.guardGate();
	san3.highFivesGuys();

	san3.beRepaired(9);

	return (0);
}
