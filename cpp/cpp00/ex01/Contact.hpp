



#include "main.hpp"

class	Contact
{
private:
	std::string name_f;
	std::string name_l;
	std::string nickname;
	std::string number;
	std::string secret;
public:
	Contact();
	~Contact();
	void	show_all();
	void	show_for_search();
	void	set_all();
};
