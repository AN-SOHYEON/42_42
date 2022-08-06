/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:59:25 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:59:30 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	private:
		std::string	d;
	public:
		Data();
		~Data();
		Data(const Data &data);
		Data	&operator=(const Data &data);

		std::string	getD() const;
		void		setD(std::string d);
};

#endif
