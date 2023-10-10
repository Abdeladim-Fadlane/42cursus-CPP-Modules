
#include"AMateria.hpp"
#include"Character.hpp"
#include"MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
int main()
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

    tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    
    // me->unequip(2);
    // me->unequip(0);
    // me->unequip(1);
    // me->unequip(3);

    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);




    delete bob;
    delete me;
    delete src;
    //system("leaks Polymorphism");
    // return 0;
    return 0;
}