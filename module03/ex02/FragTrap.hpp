#ifndef FragTrap_HPP
#define FragTrap_HPP
#include<iostream>
#include<string>
#include"ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(const std::string& target);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif