


#include "main.hpp"

// class PhoneBook
// {
// 	private:
// 		Contact *pb = new Contact[8];
// 		int		old_contact;
// 		int		is_max; // 지워도 될듯
// 		void	get_contact(int index);

// 	public:
// 		PhoneBook();	//Constructor
// 		~PhoneBook();	//Destructor    delete 해야하나?
// 		Contact *ft_add();
// 		void	ft_search();
// };

PhoneBook::PhoneBook()
{
	old_contact = 0;
	is_max = 0;			// mean number of pb	
}

PhoneBook::~PhoneBook()
{
	std::cout << "GoodBye AWESOME PHONEBOOK" << std::endl;
}

void	PhoneBook::get_contact(int index)	// search에서 원하는 index의 contact를 출력하도록 한다. 
{
	pb[index - 1].show_all();
}

Contact	*PhoneBook::addContact()
{
	pb[old_contact].set_all();
	old_contact = (old_contact + 1) % 8;
	if (is_max < 8)
		is_max++;
	return (pb);
}

void	PhoneBook::searchPhoneBook()
{
	int	i;
	int	index;

	std::cout << std::setw(10) << std::left << "index" << "|" << std::setw(10) << std::left << "firstname" << "|" << std::setw(10) << std::left << "lastname" << "|" << std::setw(10) << std::left << "nickname" << std::endl;
	i = 0;
	while (i < is_max)
	{
		std::cout << std::setw(10) << std::left << i + 1 << "|";
		pb[i].show_for_search();
		i++;
	}
	while (1)
	{
		std::cout << "choose index : ";	
		std::cin >> index;
		if (index > 0 && index < 9)
			break;
		std::cout << "you can choose 1 to 8" << std::endl;
	}
	pb[index - 1].show_all();
}