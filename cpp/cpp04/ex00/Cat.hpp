


#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &cat);
		virtual	~Cat();
		Cat	&operator=(const Cat &cat);

		void	makeSound() const; //const 이유?
};

#endif