/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:58:10 by san               #+#    #+#             */
/*   Updated: 2022/07/28 13:58:15 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
	private:
		Contact pb[8];
		int		old_contact;
		int		is_max;
		void	get_contact(int index);

	public:
		PhoneBook();
		~PhoneBook();
		Contact *addContact();
		void	searchPhoneBook();
};

#endif