



#include "main.hpp"

class PhoneBook
{
	private:
		Contact *pb = new Contact[8];
		int		old_contact;
		int		is_max; // 지워도 될듯
		void	get_contact(int index);

	public:
		PhoneBook();	//Constructor
		~PhoneBook();	//Destructor    delete 해야하나?
		Contact *ft_add();
		void	ft_search();
};

PhoneBook::PhoneBook()
{
	old_contact = -1;
	is_max = 0;			// mean number of pb
}

void	PhoneBook::get_contact(int index)	// search에서 원하는 index의 contact를 출력하도록 한다. 
{
	pb[index - 1].show_all();
}

Contact	*PhoneBook::ft_add()
{
	// if (is_max == 8)	// max면 old_contact에 정보 갈아끼우기 
	// {
		pb[old_contact].set_all();
		old_contact = (old_contact + 1) % 8;
	// }
		if (is_max < 8)
			is_max++;

}

void	PhoneBook::ft_search()
{
	int	i;
	int	index;

	i = 0;
	while (i < is_max)
	{
		std::cout << i + 1;
		pb[i].show_for_search();
	}
	std::cin >> index;
	pb[index + 1].show_all();
}