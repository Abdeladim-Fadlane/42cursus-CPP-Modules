#ifndef HUMANB_HPP
#define HUMANB_HPP
#endif
#include"Weapon.hpp"
class HumanB
{
    private:
        std::string name;
        Weapon *weaponPtr = NULL;
    public:
        HumanB(std::string humanName) : name(humanName){}
        void setWeapon(Weapon& newWeapon);
        void attack();
};