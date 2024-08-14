#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	index = 0;
	contact_i = 0;
}

PhoneBook::~PhoneBook() 
{}

bool	check_name(std::string str){
	for (size_t i=0; i<str.length();i++)
	{
		if (isalpha(str[i]) == 0)
			return (false);
	}
	return (true);
}

bool	check_phone(std::string str){
	for (size_t i=0; i<str.length(); i++){
		if (isnumber(str[i]) == 0 && str[i] != '-')
			return (false);
	}
	return (true);
}

bool check_print(std::string str){
	for (size_t i=0; i<str.length(); i++){
		if (iswprint(str[i]) == 0)
			return (false);
	}
	return (true);
}

void    PhoneBook::AddContact(){
    Contact     contact;
    std::string FN;
	std::string LN;
	std::string NN;
	std::string PN;
	std::string DS;

    if (index == 8)
        index = 0;

    std::cout << "Enter first name: ";
    std::getline(std::cin, FN);

	if (std::cin.eof() || check_name(FN) == false){
        std::cout << "Error: Input Cancelled\n";
        return ;
    }

    std::cout << "Enter last name: ";
    std::getline(std::cin, LN);

	if (std::cin.eof() || check_name(LN) == false){
        std::cout << "Error: Input Cancelled\n";
        return ;
    }

    std::cout << "Enter nickname: ";
    std::getline(std::cin, NN);

	if (std::cin.eof() || check_print(NN) == false){
        std::cout << "Error: Input Cancelled\n";
        return ;
    }

    std::cout << "Enter phone number: ";
    std::getline(std::cin, PN);

	if (std::cin.eof() || check_phone(PN) == false){
        std::cout << "Error: Input Cancelled\n";
        return ;
    }

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, DS);

    if (std::cin.eof() || check_print(DS) == false){
        std::cout << "Error: Input cancelled\n";
        return ;
    }

    contact.set_FirstName(FN);
    contact.set_LastName(LN);
    contact.set_NickName(NN);
    contact.set_PhoneNumber(PN);
    contact.set_DarkestSecret(DS);
    contacts[index] = contact;
    index++;
    if (contact_i < 8)
        contact_i++;
}

void	print_info(std::string str){
	if (str.length() < 11)
		std::cout << '|' << std::setw(10) << str;
	else
		std::cout << '|' << str.substr(0,9) << '.';
}

void	PhoneBook::SearchContact(){
	int idx;

	if (contact_i == 0){
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	
	for (int i=0; i<contact_i; i++){
		std::cout << std::setw(10) << i + 1;
		print_info(contacts[i].get_FirstName());
		print_info(contacts[i].get_LastName());
		print_info(contacts[i].get_NickName());
		std::cout << std::endl;
	}

	std::cout << "Input index:";
	std::cin >> idx;
	std::cin.ignore();
	if (idx > contact_i){
		std::cout << "Error: retry again\n";
		return ;
	}

	std::cout << "FirstName: " << contacts[idx - 1].get_FirstName() << '\n';
	std::cout << "LastName: " << contacts[idx - 1].get_LastName() << '\n';
	std::cout << "NickName: " << contacts[idx - 1].get_NickName() << '\n';
	std::cout << "PhoneNumber: " << contacts[idx - 1].get_PhoneNumber() << '\n';
	std::cout << "DarkestSecert: " << contacts[idx - 1].get_DarkestSecret() << '\n';

}
