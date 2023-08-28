#ifndef HUMANA_HPP
#define HUMANA_HPP
#endif
#include <iostream>

#ifndef HUMANA_HPP
#define HUMANA_HPP
#endif

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA(std::string humanName,  Weapon& humanWeapon)
            : name(humanName), weapon(humanWeapon) {}
        void attack();
};