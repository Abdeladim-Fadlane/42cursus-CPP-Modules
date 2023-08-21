
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#endif
#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        
        Zombie(const std::string& str) : name(str) {} 
        std::string  getName();
        void setName(std::string str);
        void announce( void );
        ~Zombie();
};

Zombie* newZombie(std::string name );
void    randomChump(std::string name);