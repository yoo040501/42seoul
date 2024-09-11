#include "Cat.hpp"
#include "Dog.hpp"

// void	aaa(void){
// 	system("leaks ex01");
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	const Animal* a = j;
	
	i->makeSound();
	j->makeSound();
	a->makeSound();
	delete j;
	delete i;
	//delete a;
	//atexit(aaa);
	return 0;
}
