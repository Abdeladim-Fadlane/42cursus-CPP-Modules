#ifndef FragTrap_HPP
#define FragTrap_HPP
#include<iostream>
#include<string>
#include"ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& target);
        FragTrap &operator=(const FragTrap& obj);
        FragTrap(const FragTrap& target);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif