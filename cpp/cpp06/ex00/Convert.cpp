/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:35 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:58:36 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Convert.hpp"




class Convert
{
	private:
		char		type;
		std::string	value;
	public:
		Convert();
		Convert(char type, std::string value);
		Convert(const Convert &convert);
		~Convert();
		Convert	&operator=(const Convert &convert);

		void	conversion();
		void	convertChar();
		void	convertInt();
		void	convertFloat();
		void	convertDouble();
		
	class	NoType : public std::exception
	{
		public :
			const char	*what() const throw();
	};

};

void	Convert::convertChar()
{

}

void	Convert::convertInt()
{

}

void	Convert::convertFloat()
{

}

void	Convert::convertDouble()
{

}


void	Convert::conversion()
{
	switch (this->type)
	{
		case ('c'):
			convertChar();
			break;
		case ('i'):
			convertInt();
			break;
		case ('f'):
			convertFloat();
			break;
		case ('d'):
			convertDouble();
			break;
		default : 
			throw (NoType());
	}
}




Convert::Convert(/* args */)
{
}

Convert::Convert(char type, std::string value)
{

}

Convert::~Convert()
{
}
