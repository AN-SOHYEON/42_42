/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:01:28 by san               #+#    #+#             */
/*   Updated: 2022/08/05 15:01:29 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	std::cout << "======== san test ===========" << std::endl << std::endl;
	
	char	e = 'e';
	char	f = 'f';
	std::cout << "min( " << e << ", " << f << " ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( " << e << ", " << f << " ) = " << ::max( e, f ) << std::endl;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;

	return 0;
}
