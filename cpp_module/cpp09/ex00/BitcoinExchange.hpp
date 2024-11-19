#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>

void	bitcoinexchange(char *file);

class OpenFailException: public std::exception{
	public:
		virtual const char* what() const throw();
};

class BadInfoException: public std::exception{
	public:
		virtual const char* what() const throw();
};
