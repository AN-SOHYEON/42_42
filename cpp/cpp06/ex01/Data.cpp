/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:59:21 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:59:22 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(const Data &data)
{
	this->d = data.getD();
}

Data	&Data::operator=(const Data &data)
{
	this->d = data.getD();
	return (*this);
}

std::string	Data::getD() const
{
	return (this->d);
}

void	Data::setD(std::string d)
{
	this->d = d;
}
