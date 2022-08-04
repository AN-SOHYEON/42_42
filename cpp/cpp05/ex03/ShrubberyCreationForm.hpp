



#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		std::string	t_name;
	public:
		ShrubberyCreationForm();
		virtual	~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &scf);

		virtual void	execute(const Bureaucrat &bureaucrat) const;
		std::string		getTName() const;
};

#endif
