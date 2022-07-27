



 #include "main.hpp"

// class	Contact
// {
// private:
// 	std::string name_f;
// 	std::string name_l;
// 	std::string nickname;
// 	std::string number;
// 	std::string secret;
// public:
// 	Contact();
// 	~Contact();
// 	void	show_all();
// 	void	show_for_search();
// 	void	set_all();
// };

void	Contact::show_all()
{
	// 선택한 연락처의 모든 정보를 한줄씩 출력한다. 
	std::cout << "first name : " << name_f << std::endl;
	std::cout << "last name : " << name_l << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phonenumber : " << number << std::endl;
	std::cout << "darkest secret : " << secret << std::endl;
}

void	Contact::show_for_search()
{
	//////////
	// search에 대한 동작을위한 정보를 출력한다. .
	// 	4개 행으로 저장된 contact 보여주기
	// index, first name,, last name nickname
	// 각 열은 너비 10문자로 가로 정렬되어 있어야 한다. . 
	// | 로 문자를 분리
	// 문자가 column보다 길면 잘라내고 .으로 대체한다. 
	// index가 범위를 벗어날 때 어떻게 작동할 건지 정의하기 
	// 한 contact당 한줄에 나타내기
	std::cout << "first name : " << name_f << std::endl;
	std::cout << "last name : " << name_l << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
}

void	Contact::set_all()
{
	std::cout << "first name : ";
	std::cin >> name_f;
	std::cout << std::endl;

	std::cout << "last name : ";
	std::cin >> name_l;
	std::cout << std::endl;

	std::cout << "nickname : ";
	std::cin >> nickname;
	std::cout << std::endl;

	std::cout << "phonenumber(dont use \"-\") : ";
	std::cin >> number;
	std::cout << std::endl;

	std::cout << "darkest secret : ";
	std::cin >> secret;
	std::cout << std::endl;

	// 연락처에 정보를 기입한다. 
}

