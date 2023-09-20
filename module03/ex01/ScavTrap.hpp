#ifndef SCAVTARAP_HPP
#define SCAVTARAP_HPP
#include<iostream>
#include<string>
#include"ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
    public:
    ScavTrap(const std::string& target);
    ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};

#endif