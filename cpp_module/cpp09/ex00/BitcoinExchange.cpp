#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *av)
{
	exchange(av);
}

BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::isLeap(int year)
{
    return ((year % 4==0 && year % 100 != 0) || year % 400 == 0) ? false: true; // true == 평년
}

bool	BitcoinExchange::check_date(int year, int month, int date)
{
    if (date < 1 || date > 31)
        return false;
    const int m[5] = {2, 4, 6, 9, 11};
    for (int i=0;i<5;i++)
    {
        if (month == m[i] && date == 31)
            return false;
    }
    if (month == 2 && date > 29)
        return false;
    if (month == 2 && isLeap(year) && date == 29) // 평년일때는 29일 X
        return false;
    return true;
}

bool    BitcoinExchange::is_valid_date(std::string info)
{
    std::string tmp;
    int year;
    int month;
    int date;
    std::string::size_type del = info.find('-'); // 9999-99-99 형식
    if (del == std::string::npos) // 9999-가 없으면 에러
        return false;
    tmp = info.substr(0, del); //몇년인지 확인
    if (tmp.length() != 4 || tmp[0] == '-' || tmp[0] == '+') //년도는 4자리수로
        return false;
    std::istringstream iss(tmp);
    iss >> std::noskipws >> year;
    if (!iss.eof() || iss.fail())
        return false;

    std::string::size_type del2 = info.find('-', 6);
    if (del2 == std::string::npos) // 99-가 없으면 에러
        return false;
    tmp = info.substr(del + 1, 2); //몇년인지 확인
    if (tmp.length() != 2 || tmp[0] == '-' || tmp[0] == '+') //월은 2자리수로
        return false;
    std::istringstream is(tmp);
    is >> std::noskipws >> month;
    if (!is.eof() || is.fail())
        return false;
    if (month < 1 || month > 12)
        return false;
    
    tmp = info.substr(del2 + 1);
    if (tmp.length() != 2 || tmp[0] == '-' || tmp[0] == '+') //일은 2자리수로
        return false;
    std::istringstream i(tmp);
    i >> std::noskipws >> date;
    if (!i.eof() || i.fail())
        return false;
    if (check_date(year, month, date) == false)
        return false;
    return true;
}

void    BitcoinExchange::checkfile(char *file, std::map<std::string, float> data)
{
    std::ifstream   infile(file);
    std::string     info;
    std::string     date;
    float           number;

    std::getline(infile, info);
    if (info != "date | value") // 헤더 정보 확인
        throw(std::bad_exception());
    while (1)
    {
        std::getline(infile, info);
        if (infile.eof())
            break ;
        std::string::size_type delimiter = info.find(" | "); //모든 정보를 " | "로 자름
        if (delimiter == std::string::npos) // delimiter가 없으면 에러
        {
            std::cout << "Error: not following format" << std::endl;
            continue;
        }
        date = info.substr(0, delimiter); // delimiter 전까지는 날짜
        if (is_valid_date(date) == false)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::istringstream iss(info.substr(delimiter + 3)); //value확인
        iss >> std::noskipws >> number;
        if (!iss.eof() || iss.fail())
        {
            std::cout << "Error: bad input => " << info.substr(delimiter + 3) << std::endl;
            continue;
        }
        if (number > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        else if (number < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = data.upper_bound(date);
        if (it != data.begin())
        {
            --it;
            std::cout << date << " => " << number << " = " << it->second * number << std::endl;
        }
        else
        {
            std::cout << "Error: no data available for date " << date << std::endl;
        }
    }
}

void    BitcoinExchange::getBitcoinInfo(std::map<std::string, float> &data)
{
    std::ifstream infile("data.csv");
    std::string contents;

    if (!infile.is_open())
        throw (OpenFailException());
    std::getline(infile, contents);
    if (contents != "date,exchange_rate")
        throw (BadInfoException());
    while (1)
    {
        std::getline(infile, contents);
        if (infile.eof())
            break ;
        std::string::size_type delimiter = contents.find(',');
        if (delimiter == std::string::npos)
            throw BadInfoException();
		std::string date = contents.substr(0, delimiter);
		float	value;
		std::istringstream iss(contents.substr(delimiter + 1)); //value확인
        iss >> std::noskipws >> value;
        if (!iss.eof() || iss.fail())
            throw BadInfoException();
		if (is_valid_date(date) == false)
			throw BadInfoException();
       	data[date] = value;//static_cast<float>(atof(contents.substr(delimiter + 1).c_str()));
    }
}

void    BitcoinExchange::exchange(char *file){
    std::map<std::string, float> data;
    getBitcoinInfo(data);
    checkfile(file, data);
}

const char* OpenFailException::what() const throw() {
    return "\033[0;31mFile Open Fail!\033[0m";
}

const char* BadInfoException::what() const throw() {
    return "\033[0;31mBad Info!\033[0m";
}
