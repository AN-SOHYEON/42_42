/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:14:59 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:15:00 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wrongAnimal);
		~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal &wrongAnimal);

		std::string	getType() const;
		void		makeSound() const;
};

#endif
