/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:39 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:58:45 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Convert
{
	private:
		char		type;
		std::string	value;

		std::string c;
		int			i;
		float		f;
		double		d;

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

		bool	IntBound();

		
	class	NoTypeException : public std::exception
	{
		public :
			const char	*what() const throw();
	};

};

#endif
