#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
    
std::string  Zombie::getName(void)
{
    return(name);
}

void Zombie::setName(std::string str)
{
    name = str;
}

Zombie::~Zombie()
{
    std::cout << "Destructor destroyed: " << name << std::endl;
}