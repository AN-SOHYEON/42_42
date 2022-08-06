/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:59:45 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:59:46 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstdint>

static uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data	data;

	data.setD("sansan");

	uintptr_t	san = serialize(&data);
	Data	*san_de = deserialize(san);

	std::cout << std::endl;
	std::cout << "result of se->dese : " << san_de->getD() << std::endl;
	std::cout << std::endl;
	std::cout << "=================  ==================" << std::endl;
	std::cout << "data add   : " << &data << std::endl;
	std::cout << "data add   : " << san_de << std::endl;
	std::cout << std::endl;

	std::cout << "data value   : " << data.getD() << std::endl;
	std::cout << "san_de value : " << san_de->getD() << std::endl;
	std::cout << std::endl;

	return (0);
}
