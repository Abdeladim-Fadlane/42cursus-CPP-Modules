#include"Zombie.hpp"

void randomChump( std::string name )
{
    Zombie *Foo =  newZombie(name);
    Foo->announce();
    delete Foo;
}