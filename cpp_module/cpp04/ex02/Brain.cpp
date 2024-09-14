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
	for (int i=0;i<100;i++)
		this->ideas[i] = Brain.getIdea(i);
	std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain&	Brain::operator=(const Brain& B){
	if (this != &B)
	{
		for (int i=0;i<100;i++)
			this->ideas[i] = B.getIdea(i);
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain(void){
	std::cout << "Brain Destructor called" << std::endl;
}

std::string	Brain::getIdea(int n) const{
	if (n >= 0 && n < 100)
		return (this->ideas[n]);
	return (this->ideas[0]);
}

void	Brain::setIdea(int n, std::string word){
	if (n >= 0 && n < 100)
		this->ideas[n] = word;
	else
		this->ideas[0] = word;
}
