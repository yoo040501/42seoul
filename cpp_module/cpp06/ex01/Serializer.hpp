#pragma once

#include <iostream>
typedef unsigned long	uintptr_t;

struct Data
{
	int			n[10];
	int			*a;
	std::string	len;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const& S);
		Serializer& operator=(Serializer const& copy);

	public:
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
