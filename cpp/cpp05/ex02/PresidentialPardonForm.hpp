

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ppf);

		void	execute(const Bureaucrat &Bureaucrat) const;
};

#endif