

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) 
{
	std::cout << "[DEBUG]" << std::endl 
				<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n "
				<< "I just love it!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
		<< "I cannot believe adding extra bacon cost more money.\n"
		<< "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
			<< "I think I deserve to have some extra bacon for free.\n"
			<< "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
			<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}

// const Harl::level Harl::LEVELS[] = {
//     &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::complain(std::string level) 
{
	const std::string l[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*LEVELS[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (level == l[i])
		{
			(this->*LEVELS[i])();
			break;
		}
	}
}
