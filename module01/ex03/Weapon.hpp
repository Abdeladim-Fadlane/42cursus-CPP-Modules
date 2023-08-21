#ifndef WEAPON_HPP
#define WEAPON_HPP
#endif
#include <iostream>
#include <string>

class   Weapon
{
    private: 
        std::string type;

    const std::string getType(std::string& str)
    {
        return(type);
    }
    void    setType(std::string str)
    {
        type = str;
    }
    
};