

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &intern)
{
	(void)intern;
}

Intern	&Intern::operator=(const Intern *intern)
{
	(void) intern;
	return (*this);
}

Form	*Intern::_robot(std::string t_name)
{
	Form	*tmp = new RobotomyRequestForm(t_name);
	return (tmp);
}

Form	*Intern::_shrubbery(std::string t_name)
{
	Form	*tmp = new ShrubberyCreationForm(t_name);
	return (tmp);
}

Form	*Intern::_president(std::string t_name)
{
	Form	*tmp = new PresidentialPardonForm(t_name);
	return (tmp);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	const	std::string f[3] = {"ROBOT", "SHRUBBERY", "PRESIDENT"};
	Form	*(Intern::*fp[3])(std::string t);
	Form	*tmp;

	tmp = NULL;
	fp[0] = &Intern::_robot;
	fp[1] = &Intern::_shrubbery;
	fp[2] = &Intern::_president;

	for (int i = 0; i < 3; i++)
	{
		if (name == f[i])
		{
			tmp = (this->*fp[i])(target);
			break;
		}
	}
	if (!tmp)
		throw (Intern::InternFailToCreateForm());
	std::cout << "Intern creates " << tmp->getName() << std::endl;
	return (tmp);
}

const char	*Intern::InternFailToCreateForm::what() const throw() 
{
	return "Intern fail to create Form. try again.";
}