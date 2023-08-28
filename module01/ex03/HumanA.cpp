
#include"Weapon.hpp"
#include"HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with their " 
    << weapon.getType() << std::endl;
}