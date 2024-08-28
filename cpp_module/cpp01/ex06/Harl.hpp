#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl{

	enum levels {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		UNKNOWN
	};
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	print(int level);
	levels	getlevel( std::string const level);

	public:
		void	complain(std::string level);
};

#endif
