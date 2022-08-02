

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none")
{
	this->grade = 150;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.getName())
{
	this->grade = bureaucrat.getGrade();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	// this->name = bureaucrat.getName();
	*(const_cast<std::string *>(&this->name)) = bureaucrat.getName();
	this->grade = bureaucrat.getGrade();

	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::upGrade()
{
	this->grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::downGrade()
{
	this->grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
  return "Grade is over range (High)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
  return "Grade is over range (Low)";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade is " << bureaucrat.getGrade();
	return (out);
}