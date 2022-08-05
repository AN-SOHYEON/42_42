/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:12:40 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:12:41 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("FORM")
{
	this->is_signed =  false;
	this->sign_grade = 1;
	this->exe_grade = 150;
}

Form::~Form() {}

Form::Form(std::string name, bool is_signed, int sign_grade, int exe_grade)
	: name(name)
{
	if (sign_grade < 1 || exe_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || exe_grade > 150)
		throw GradeTooLowException();
	else
	{
		this->is_signed = is_signed;
		this->sign_grade = sign_grade;
		this->exe_grade = exe_grade;		
	}
}

Form::Form(const Form &form) : name(form.getName())
{
	this->is_signed = form.getIsSigned();
	this->sign_grade = form.getSignGrade();
	this->exe_grade = form.getExeGrade();		
}

Form	&Form::operator=(Form const &form)
{
	this->is_signed = form.getIsSigned();
	this->sign_grade = form.getSignGrade();
	this->exe_grade = form.getExeGrade();

	return (*this);
}

const std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->is_signed);
}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int Form::getExeGrade() const
{
	return (this->exe_grade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade)
		throw Form::GradeTooLowException();
	if (is_signed == true)
		std::cout << name << " is aleady signed" << std::endl;
	else
		is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is over range (High)";
}

const char	*Form::GradeTooLowException::what() const throw() 
{
	return "Grade is over range (Low)";
}

const char	*Form::FormIsNotSigned::what() const throw() 
{
	return "Form did not get permit";
}

const char	*Form::FailToExecute::what() const throw() 
{
	return "Fail to Execute. please try again.";
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form : " << form.getName() << " / Sign : " << form.getIsSigned() 
		<< "\nthis form can be signed by only bureaucrat who has " << form.getSignGrade() 
		<< "or higher levels.\n" 
		<< "this form can be executed by only bureaucrat who has " << form.getExeGrade()
		<< "or higher levels." << std::endl;
		 
	return (out);
}
