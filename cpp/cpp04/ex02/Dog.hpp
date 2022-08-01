


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

		void	makeSound() const; //const 이유?
		void	printAllBrain() const;
		void	printBrain(int i) const;
		void	setBrain(std::string str, int i);
		Brain	*getBrain() const;
};

#endif
