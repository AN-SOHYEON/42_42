/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:50 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:22:51 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &animal);
		virtual	~Animal();
		Animal	&operator=(const Animal &animal);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

#endif
