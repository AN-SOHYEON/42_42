/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:49:58 by san               #+#    #+#             */
/*   Updated: 2022/07/29 12:49:59 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

int main(void)
{
	Harl	Harl;

	Harl.complain("DEBUG");
	Harl.complain("INFO");
	Harl.complain("WARNING");
	Harl.complain("ERROR");
	return (0);
}
