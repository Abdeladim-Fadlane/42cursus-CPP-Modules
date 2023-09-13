#include"Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType) {}
std::string Weapon::getType()
{
    return type;
}
void Weapon::setType(std::string newType)
{
    type = newType;
}