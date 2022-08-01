


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		int	is_keeper;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		virtual		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &scavTrap);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif