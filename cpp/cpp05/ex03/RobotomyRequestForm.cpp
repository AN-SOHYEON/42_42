/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:16:09 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:16:10 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: Form("Robot Request Form", false, 72, 45) 
{
	t_name = "default";
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: Form("Robot Request Form", false, 72, 45) 
{
	t_name = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
	: Form (rrf.getName(), rrf.getIsSigned(), rrf.getSignGrade(), rrf.getExeGrade()) 
{
	this->t_name = rrf.getTName();
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	this->t_name = rrf.getTName();
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false)
	{
		throw (Form::FormIsNotSigned());
	}
	if (bureaucrat.getGrade() > this->getExeGrade())
	{
		throw (Form::GradeTooLowException());
	}
	
	int	rand_num;

	srand(time(NULL));
	rand_num = rand() % 100 + 1;

	// for (int i = 0; i < 10; i++)
	// {
	// 	rand_num = rand() % 100 + 1;
	// 	if (rand_num > 50)
	// 		break;
	// }

	if (rand_num >= 50)
	{
		std::cout << "dddrilll..." << rand_num << std::endl;
		std::cout << t_name << " has been robotomized successfully." << std::endl;
		std::cout << "This Form is executed by bureaucrat " << bureaucrat.getName() << std::endl;
	}
	else 
	{
		throw (Form::FailToExecute());
	}
}

std::string	RobotomyRequestForm::getTName() const
{
	return (this->t_name);
}
