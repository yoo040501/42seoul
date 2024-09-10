#include "Cat.hpp"
#include "Dog.hpp"

void	aaa(void){
	system("leaks ex01");
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	
	delete j;
	delete i;
	atexit(aaa);
	return 0;
}
