

#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		Form	*_robot(std::string t_name);
		Form	*_shrubbery(std::string t_name);
		Form	*_president(std::string t_name);

	public:
		Intern();
		~Intern();
		Intern(const Intern &intern);
		Intern	&operator=(const Intern *intern);

		Form	*makeForm(std::string name, std::string target);

		class	InternFailToCreateForm : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
