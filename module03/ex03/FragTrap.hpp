#ifndef FragTrap_HPP
#define FragTrap_HPP
#include<iostream>
#include<string>
#include"ClapTrap.hpp"

class FragTrap :public virtual  ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& target);
        FragTrap &operator=(const FragTrap& obj);
        ~FragTrap();
        FragTrap(const FragTrap& target);
        void highFivesGuys(void);
};

#endif