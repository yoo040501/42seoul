#include "PhoneBook.hpp"
#include <cstring>

int main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Enter a command: [ADD / SEARCH / EXIT]" << std::endl;
		getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			return (0);
		else if (command == "ADD")
		{
			phonebook.AddContact();
		}
		else if (command == "SEARCH")
		{
			phonebook.SearchContact();
		}
		else
		{
			std::cout << "try again" << std::endl;
		}
		if (std::cin.eof())
		{
			std::clearerr(stdin);
			std::cin.clear();
			//std::cin.ignore();
		}
	}
	return (0);
}
