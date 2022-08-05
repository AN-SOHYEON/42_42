/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:16:02 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:16:03 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	t_name;
	public:
		PresidentialPardonForm();
		virtual	~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ppf);

		virtual void	execute(const Bureaucrat &Bureaucrat) const;
		std::string		getTName() const;
};

#endif
