#pragma once

#include <iostream>

class Harl{
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};
