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

		std::string			get_idea(int n) const;
		const std::string	*get_all(void) const;
		void				set_idea(int n, std::string word);
};
