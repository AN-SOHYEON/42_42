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
# include <iostream>

Base	*generate(void)
{
	int	i;

	srand(time(NULL));	
	i = rand() % 3 + 1;
	switch (i)
	{
		case (1):
			return new A();
		case (2):
			return new B();
		case (3):
			return new C();
	}
	return (NULL);
}

// - A, B, C를 랜덤하게 초기화하고 base 포인터를 리턴해라. 


void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) 
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Base" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception&)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception&)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (const std::exception&)
			{
				std::cout << "Base" << std::endl;
			}
		}
	}
}

int main()
{
	Base* random_instance = generate();
	std::cout << "Check 'void identify(Base* p)': ";
	identify(random_instance);
	std::cout << "Check 'void identify(Base& p)': ";
	identify(*random_instance);
	delete random_instance;
}