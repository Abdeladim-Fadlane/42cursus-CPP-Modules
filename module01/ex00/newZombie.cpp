

#include"Zombie.hpp"
Zombie* newZombie( std::string name )
{
    Zombie *newZombie = new Zombie(name);
    newZombie->setName(name);
    return(newZombie);
}