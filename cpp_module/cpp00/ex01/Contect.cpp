#include "Contect.hpp"

Contact::Contact()
{
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNumber = "";
	DarkestSecret = "";
}

Contact::~Contact()
{}

Contact::Contact(
	std::string FirstName,
	std::string LastName,
	std::string NickName,
	std::string PhoneNumber,
	std::string DarkestSecret
	)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->NickName = NickName;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}

std::string	Contact::get_FirstName() 
{
	return (this->FirstName);
}

std::string	Contact::get_LastName() 
{
	return (this->LastName);
}

std::string	Contact::get_NickName() 
{
	return (this->NickName);
}

std::string	Contact::get_PhoneNumber() 
{
	return (this->PhoneNumber);
}

std::string	Contact::get_DarkestSecret() 
{
	return (this->DarkestSecret);
}

void	Contact::set_FirstName(std::string str)
{
	this->FirstName = str;
}

void	Contact::set_LastName(std::string str)
{
	this->LastName = str;
}

void	Contact::set_NickName(std::string str)
{
	this->NickName = str;
}

void	Contact::set_PhoneNumber(std::string str)
{
	this->PhoneNumber = str;
}

void	Contact::set_DarkestSecret(std::string str)
{
	this->DarkestSecret = str;
}
