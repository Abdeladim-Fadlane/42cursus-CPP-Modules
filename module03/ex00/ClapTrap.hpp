#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include<iostream>
#include<string>
class ClapTrap
{
    private:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;
    public:
        ClapTrap(const std::string& target);
        ClapTrap(const ClapTrap& obj);
        ClapTrap& operator =(const ClapTrap& obj);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif