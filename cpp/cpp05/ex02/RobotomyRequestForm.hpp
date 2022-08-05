/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:13:37 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:13:40 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form
{
	private:
		std::string	t_name;
	public:
		RobotomyRequestForm();
		virtual	~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &rrf);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rrf);

		virtual void	execute(const Bureaucrat &bureaucrat) const;
		std::string		getTName() const;
};

#endif
