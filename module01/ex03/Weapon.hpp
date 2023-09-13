#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon 
{
    private:
        std::string type;
    public:
        Weapon(std::string weaponType);
        std::string getType();
        void setType(std::string newType);
};
#endif