#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void leakcheck(void){
	system("leaks Interface");
}

int main()
{
	std::cout << "-----------------Subject------------------" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "-------------------------------------------" << std::endl;


	// std::cout << "-------------------test--------------------" << std::endl;
	// {
	// 	IMateriaSource* spell = new MateriaSource();
	// 	spell->learnMateria(new Ice());
	// 	spell->learnMateria(new Cure());
	// 	spell->learnMateria(new Ice());
	// 	spell->learnMateria(new Cure());
	// 	Floor*		adr = new Floor();
	// 	ICharacter* Yuki = new Character("Yuki");
	// 	ICharacter* bot = new Character("bot");


	// 	Yuki->equip(spell->createMateria("ice"));
	// 	Yuki->equip(spell->createMateria("cure"));
	// 	Yuki->equip(spell->createMateria("cure"));
	// 	Yuki->equip(spell->createMateria("ice"));
		
	// 	Yuki->unequip(0);
	// 	Yuki->use(0, *bot);
	// 	Yuki->use(1, *bot);
	// 	std::cout << "\n-----------delete all---------------\n" << std::endl;
	// 	delete bot;
	// 	delete Yuki;
	// 	delete spell;
	// 	delete adr;
	// }

	// std::cout << "\n----------------캐릭터 깊은 복사 테스트---------------\n" << std::endl;
	// Character *a = new Character("aaa");
	// Character *b = new Character("bbb");

	// *a = *b;

	// delete a;
	// delete b;
	//atexit(leakcheck);
	return 0;
}
