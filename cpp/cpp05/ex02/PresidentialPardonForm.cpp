/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:13:11 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:13:17 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: Form("Presidential Pardon Form", false, 25, 5) 
{
	t_name = "default";
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: Form("Presidential Pardon Form", false, 25, 5) 
{
	t_name = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
	: Form (ppf.getName(), ppf.getIsSigned(), ppf.getSignGrade(), ppf.getExeGrade()) 
{
	this->t_name = ppf.getTName();
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
	this->t_name = ppf.getTName();
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false)
	{
		throw (Form::FormIsNotSigned());
	}
	if (bureaucrat.getGrade() > this->getExeGrade())
	{
		throw (Form::GradeTooLowException());
	}
	std::cout << this->t_name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << "This Form is executed by bureaucrat " << bureaucrat.getName() << std::endl;
}

std::string	PresidentialPardonForm::getTName() const
{
	return (this->t_name);
}
