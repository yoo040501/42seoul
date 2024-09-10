#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain Constructor Called" << std::endl;
	std::stringstream	ss;

	for (int i=0;i<100;i++){
		ss.str("");
		ss << i;
		this->ideas[i] = "Brain" + ss.str();
	}
}

Brain::Brain(const Brain& Brain){
	std::cout << "		Brain Copy Constructor Called" << std::endl;
	*this = Brain;
	for (int i=0;i<100;i++)
		this->ideas[i] = Brain::get_idea(i);
}

Brain&	Brain::operator=(const Brain& B){
	std::cout << "		Brain Copy assignment operator called" << std::endl;
	if (this != &B)
	{
		for (int i=0;i<100;i++)
			this->ideas[i] = B.get_idea(i);
	}
	return (*this);
}

Brain::~Brain(void){
	std::cout << "		Brain Destructor called" << std::endl;
}

std::string	Brain::get_idea(int n) const{
	return (this->ideas[n]);
}

const std::string*	Brain::get_all(void) const{
	return this->ideas;
}
void	Brain::set_idea(int n, std::string word){
	this->ideas[n] = word;
}
