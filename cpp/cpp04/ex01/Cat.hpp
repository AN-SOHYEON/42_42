/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:21:57 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:21:59 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat &cat);
		virtual	~Cat();
		Cat	&operator=(const Cat &cat);

		void	makeSound() const;
		void	printAllBrain() const;
		void	printBrain(int i) const;
		void	setBrain(std::string str, int i);
		Brain	*getBrain() const;
};

#endif
