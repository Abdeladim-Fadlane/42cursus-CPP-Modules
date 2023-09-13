#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA(std::string humanName,  Weapon& humanWeapon);
        void attack();
};
#endif