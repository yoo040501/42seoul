#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error: could not open file");
		
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
}