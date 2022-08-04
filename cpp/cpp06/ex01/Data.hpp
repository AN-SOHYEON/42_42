
#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	private:
		std::string	d;
	public:
		Data();
		~Data();
		Data(const Data &data);
		Data	&operator=(const Data &data);

		std::string	getD() const;
		void		setD(std::string d);
};

#endif