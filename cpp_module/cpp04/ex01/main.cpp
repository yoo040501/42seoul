#include "Cat.hpp"
#include "Dog.hpp"

// void	aaa(void){
// 	system("leaks ex01");
// }

int main()
{
	{
		const Animal *Animals[10];

		for (int i = 0; i < 10; i++)
		{
			if (i < 10 / 2)
				Animals[i] = new Dog();
			else
				Animals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		std::cout << Animals[0]->getType() << std::endl;
		std::cout << Animals[5]->getType() << std::endl;

		Brain *brain = new Brain();
		brain = Animals[0]->getBrain();
		brain->setIdea(0, "Hello");
		brain->setIdea(1, "World");
		std::cout << Animals[0]->getBrain()->getIdea(0) << std::endl;
		std::cout << Animals[0]->getBrain()->getIdea(1) << std::endl;
		for (int i = 0; i < 10; i++)
			delete Animals[i];
		delete brain;
	}
	std::cout << "------------Deep copy Dog class------------" << std::endl;
	{
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		Dog *dogC = new Dog;
		Dog *dogD = new Dog;

		*dogC = *dogD;

		delete dogA;
		delete dogB;
		delete dogC;
		delete dogD;
	}

	std::cout << "----------Deep copy Cat class-------------" << std::endl;
	{
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		Cat *catC = new Cat;
		Cat *catD = new Cat;

		*catC = *catD;
		delete catA;
		delete catB;
		delete catC;
		delete catD;
	}
	return 0;
}

