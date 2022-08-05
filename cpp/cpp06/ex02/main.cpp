/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:00:49 by san               #+#    #+#             */
/*   Updated: 2022/08/05 15:00:51 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# include <cstdlib>
# include <ctime>

Base	*generate(void)
{
	A	*a;
	B	*b;
	C	*c;
	int	i;
	
	i = rand() % 3 + 1;
	switch (i)
	{
		case (1):
			a = new A;
			return (static_cast<Base *>(a));
			break;
		case (2):
			b = new B;
			return (static_cast<Base *>(b));
			break;
		case (3):
			c = new C;
			return (static_cast<Base *>(c));
			break;
	}	
}

// - A, B, C를 랜덤하게 초기화하고 base 포인터를 리턴해라. 



void	identify(Base* p)
{
	switch (i)
	{
		case (1):
			a = new A;
			return (static_cast<Base *>(a));
			break;
		case (2):
			b = new B;
			return (static_cast<Base *>(b));
			break;
		case (3):
			c = new C;
			return (static_cast<Base *>(c));
			break;
	}	

}
// - p의 실제 타입을 출력해라.



void	identify(Base& p)
{

}

int	main()
{

	return (0);
}
