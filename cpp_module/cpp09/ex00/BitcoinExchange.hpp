#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>


class BitcoinExchange
{
private:
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange& operator=(BitcoinExchange const &oth);
	void	exchange(char *file);
	void	getBitcoinInfo(std::map<std::string, float> &data);
	void	checkfile(char *file, std::map<std::string, float> data);
	bool	is_valid_date(std::string info);
	bool	check_date(int year, int month, int date);
	bool	isLeap(int year);

public:
	BitcoinExchange(char *av);
	~BitcoinExchange();
};

class OpenFailException: public std::exception{
	public:
		virtual const char* what() const throw();
};

class BadInfoException: public std::exception{
	public:
		virtual const char* what() const throw();
};
