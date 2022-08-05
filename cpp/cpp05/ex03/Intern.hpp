/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:15:06 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:15:09 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
