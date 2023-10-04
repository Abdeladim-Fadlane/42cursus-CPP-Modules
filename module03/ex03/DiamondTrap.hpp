#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include<iostream>
#include<string>
#include"FragTrap.hpp"
#include"ScavTrap.hpp"

class DiamondTrap : public  FragTrap, public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string& target);
        DiamondTrap(const DiamondTrap& obj);
        DiamondTrap& operator =(const DiamondTrap& obj);
        ~DiamondTrap();
        void whoAmI();
};
#endif