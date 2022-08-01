


#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(std::string str);
		Brain(const Brain &brain);
		virtual	~Brain();
		Brain	&operator=(const Brain &brain);

		void		setBrain(std::string str, int i);
		void		setAllBrain(std::string str);
		std::string	getBrain(int i) const;
};

#endif