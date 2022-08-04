


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