/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:41 by san               #+#    #+#             */
/*   Updated: 2022/08/02 16:23:43 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(const Dog &dog);
		virtual	~Dog();
		Dog	&operator=(const Dog &dog);

		void	makeSound() const;
		void	printAllBrain() const;
		void	printBrain(int i) const;
		void	setBrain(std::string str, int i);
		Brain	*getBrain() const;
};

#endif
