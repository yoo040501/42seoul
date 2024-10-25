#include "Serializer.hpp"

int main()
{
	Data data;
	data.len = "asdasd";
	data.n = 42;

	std::cout << &data << std::endl;
	std::cout << data.len << std::endl;
	std::cout << data.n << std::endl;

	uintptr_t a = Serializer::serialize(&data);
	std::cout << Serializer::serialize(&data) << std::endl;

	Data *change;
	change = Serializer::deserialize(a);
	std::cout << change << std::endl;

	std::cout << change->len << std::endl;
	std::cout << change->n << std::endl;

	uintptr_t b = 123456;

	std::cout << std::endl << b << std::endl;
	Data *test = Serializer::deserialize(b);
	std::cout << test << std::endl;
	std::cout << Serializer::serialize(test) << std::endl;
	return 0;
}
