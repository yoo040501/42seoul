#include "PhoneBook.hpp"
#include <cstring>

int main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Enter a command: [ADD / SEARCH / EXIT]" << '\n';
		getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			exit (0) ;
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
			std::cout << "try again" << '\n';
		}
		if (std::cin.eof())
		{
			std::cout << "clear\n";
			std::clearerr(stdin);
			std::cin.clear();
			//std::cin.ignore();
		}
	}
	return (0);
}
