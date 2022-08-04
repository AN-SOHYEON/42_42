

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: Form("Shrubbery Creation Form", false, 145, 137) 
{
	t_name = "default";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: Form("Robot Request Form", false, 145, 137) 
{
	t_name = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
	: Form (scf.getName(), scf.getIsSigned(), scf.getSignGrade(), scf.getExeGrade()) 
{
	this->t_name = scf.getTName();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	this->t_name = scf.getTName();
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::string	sh =	".oPYo.  o    o  .oPYo. o    o  .oPYo.  .oPYo. .oPYo.  .oPYo. o   o \n" 
						"8       8    8  8   `8 8    8  8   `8  8   `8 8.      8   `8 `b d' \n"
						"`Yooo. o8oooo8 o8YooP' 8    8 o8YooP' o8YooP' `boo   o8YooP'  `b'  \n"
						"    `8  8    8  8   `b 8    8  8   `b  8   `b .P      8   `b   8   \n"
						"     8  8    8  8    8 8    8  8    8  8    8 8       8    8   8   \n"
						"`YooP'  8    8  8    8 `YooP'  8oooP'  8oooP' `YooP'  8    8   8   \n"
						":.....::..:::..:..:::..:.....::......::......::.....::..:::..::..::\n"
						":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
						":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	
	if (this->getIsSigned() == false)
	{
		throw (Form::FormIsNotSigned());
	}
	if (bureaucrat.getGrade() > this->getExeGrade())
	{
		throw (Form::GradeTooLowException());
	}
	std::string	name = t_name + "_shrubbery";
	std::ofstream	out(name.c_str(), std::ofstream::out);
	if (!out.is_open())
	{
		throw (FailToExecute());
	}
	out << sh;
	out.close();
	std::cout << "This Form is executed by bureaucrat " << bureaucrat.getName() << std::endl;
}

std::string	ShrubberyCreationForm::getTName() const
{ 
	return (this->t_name);
}