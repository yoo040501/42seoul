#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->len = "hello";
	data->a = new int[10];
	for (int i=0;i<10;i++){
		data->n[i] = i;
		data->a[i] = i;
	}
	std::cout << data << std::endl;
	std::cout << data->len << std::endl;
	std::cout << data->n[1] << std::endl;
	std::cout << data->a[1] << std::endl;
	std::cout << std::endl;

	uintptr_t b = Serializer::serialize(data);
	std::cout << b << std::endl;

	Data *change;
	change = Serializer::deserialize(b);
	std::cout << change << std::endl;
	std::cout << std::endl;
	
	std::cout << change->len << std::endl;
	std::cout << change->n[1] << std::endl;
	std::cout << change->a[1] << std::endl;

	uintptr_t c = 123456;

	std::cout << "\n" << c << std::endl;
	Data *test = Serializer::deserialize(c);
	std::cout << test << std::endl;
	std::cout << Serializer::serialize(test) << std::endl;
	delete data;
	return 0;
}
