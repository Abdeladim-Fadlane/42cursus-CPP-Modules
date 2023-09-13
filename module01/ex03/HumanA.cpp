
#include"Weapon.hpp"
#include"HumanA.hpp"

HumanA::HumanA(std::string humanName,  Weapon& humanWeapon)
 : name(humanName), weapon(humanWeapon) {}

void HumanA::attack()
{
    std::cout << name << " attacks with their " 
    << weapon.getType() << std::endl;
}
