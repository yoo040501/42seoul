#pragma once

#include <iostream>
#include <sstream>

class Brain{
		std::string	ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain& Brain);
		Brain& operator=(const Brain &B);
		~Brain();

		std::string			getIdea(int n) const;
		void				setIdea(int n, std::string word);
};
