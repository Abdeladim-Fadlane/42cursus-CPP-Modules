#include"HumanB.hpp"

void HumanB::setWeapon(Weapon& newWeapon)
{
    weaponPtr = &newWeapon;
}
void HumanB::attack()
{
    if (weaponPtr)
        std::cout << name << " attacks with their " << weaponPtr->getType() << std::endl;
    else
        std::cout << name << " attacks whit bare hands." << std::endl;
}