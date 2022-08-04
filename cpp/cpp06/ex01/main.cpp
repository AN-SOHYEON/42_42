



#include "Data.hpp"
#include <stdint.h>	// uintptr_t



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
	std::cout << "result of se->dese : " << san_de->getD() << std::endl;

	std::cout << std::endl;
	std::cout << "=================  ==================" << std::endl;
	std::cout << "data add   : " << &data << std::endl;
	std::cout << "data add   : " << san_de << std::endl;
	std::cout << std::endl;

	std::cout << "data value   : " << data.getD() << std::endl;
	std::cout << "san_de value : " << san_de->getD() << std::endl;

	std::cout << std::endl;
}
