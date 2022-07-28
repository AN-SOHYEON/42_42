/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:56:34 by san               #+#    #+#             */
/*   Updated: 2022/07/28 13:57:15 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class	Contact
{
	private:
		std::string name_f;
		std::string name_l;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		Contact();
		~Contact();
		void	show_all();
		void	show_for_search();
		void	set_all();
};

#endif
