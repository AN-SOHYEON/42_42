


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

		void	makeSound() const; //const 이유?
		void	printAllBrain() const;
		void	printBrain(int i) const;
		void	setBrain(std::string str, int i);
		Brain	*getBrain() const;
};

#endif