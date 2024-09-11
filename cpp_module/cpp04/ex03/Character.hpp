#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria    *_inventory[4];

	public:
		Character(std::string const &name);
		Character(Character const &Character);
		~Character();

    Character&          operator=(Character const &C);

    std::string const&  getName() const;
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);
};
