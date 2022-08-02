/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:15:14 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:15:15 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &wrongCat);
		~WrongCat();
		WrongCat	&operator=(const WrongCat &wrongCat);

		void	makeSound() const;
};

#endif
