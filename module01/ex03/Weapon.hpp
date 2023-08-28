#ifndef WEAPON_HPP
#define WEAPON_HPP
#endif
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string weaponType) : type(weaponType) {}
        std::string getType();
        void setType(std::string newType);
};