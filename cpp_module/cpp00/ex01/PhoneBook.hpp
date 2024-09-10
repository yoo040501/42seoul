#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	Contact contacts[8];
	int     index;
	int     contact_i;
	public:
        PhoneBook();
        ~PhoneBook();

        void    AddContact();
        void    SearchContact();
};

#endif
