#ifndef CONTECT_HPP
# define CONTECT_HPP

# include <iostream>

class Contact {
  private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

  public:
	Contact();
	~Contact();
	Contact(
		std::string FirstName,
		std::string LastName,
		std::string NickName,
		std::string PhoneNumber,
		std::string DarkestSecret
		);
		std::string	get_FirstName();
		std::string	get_LastName();
		std::string	get_NickName();
		std::string	get_PhoneNumber();
		std::string	get_DarkestSecret();

		void	set_FirstName(std::string str);
		void	set_LastName(std::string str);
		void	set_NickName(std::string str);
		void	set_PhoneNumber(std::string str);
		void	set_DarkestSecret(std::string str);
};

#endif
