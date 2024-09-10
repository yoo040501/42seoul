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

bool	input_firstname(Contact *contact){
	std::string FN;

	while (true){
		std::cout << "Enter first name: ";
		std::getline(std::cin, FN);

		if (std::cin.eof()){
			std::cout << "\nError: Input Cancelled" << std::endl;
			delete contact;
			return (false);
		}
		if (check_name(FN) == false)
			std::cout << "Please Put English letters" << std::endl;
		else
		{
			contact->set_FirstName(FN);
			break ;
		}
	}
	return (true);
}

bool	input_lastname(Contact *contact){
	std::string LN;

	while (true){
		std::cout << "Enter last name: ";
		std::getline(std::cin, LN);

		if (std::cin.eof()){
			std::cout << "\nError: Input Cancelled" << std::endl;
			delete contact;
			return false;
		}
		if (check_name(LN) == false)
			std::cout << "Please Put English letters" << std::endl;
		else{
			contact->set_LastName(LN);
			break ;
		}
	}
	return true;
}

bool	input_phone(Contact *contact){
	std::string PN;

	while(true){
		std::cout << "Enter phone number: ";
		std::getline(std::cin, PN);

		if (std::cin.eof()){
			std::cout << "\nError: Input Cancelled\n" << std::endl;
			delete contact;
			return false;
		}
		if(check_phone(PN) == false)
			std::cout << "Please Put Number or '-'" << std::endl;
		else{
			contact->set_PhoneNumber(PN);
			break ;
		}
	}
	return (true);
}

void    PhoneBook::AddContact(){
    Contact     *contact = new Contact;
	std::string NN;
	std::string DS;

    if (index == 8)
        index = 0;
	
	if (input_firstname(contact) == false)
		return ;
	
	if (input_lastname(contact) == false)
		return ;
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, NN);

	if (std::cin.eof() || check_print(NN) == false){
        std::cout << "\nError: Input Cancelled\n" << std::endl;
		delete contact;
        return ;
    }

	if (input_phone(contact) == false)
		return ;

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, DS);

    if (std::cin.eof() || check_print(DS) == false){
        std::cout << "\nError: Input cancelled" << std::endl;
		delete contact;
        return ;
    }

    contact->set_NickName(NN);
    contact->set_DarkestSecret(DS);
    contacts[index] = *contact;
	delete contact;
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

	std::cout << "Input index: ";
	std::cin >> idx;
	std::cin.ignore();
	if (std::cin.fail() || idx > contact_i || idx == 0){
		std::cout << "\nError: retry again" << std::endl;
		std::cin.clear();
		return ;
	}

	std::cout << "FirstName: " << contacts[idx - 1].get_FirstName() << std::endl;
	std::cout << "LastName: " << contacts[idx - 1].get_LastName() << std::endl;
	std::cout << "NickName: " << contacts[idx - 1].get_NickName() << std::endl;
	std::cout << "PhoneNumber: " << contacts[idx - 1].get_PhoneNumber() << std::endl;
	std::cout << "DarkestSecert: " << contacts[idx - 1].get_DarkestSecret() << std::endl;

}
