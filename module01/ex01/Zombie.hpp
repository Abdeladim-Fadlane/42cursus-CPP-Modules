
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
        
        Zombie(){}
        std::string  getName();
        void setName(std::string str);
        void announce( void );
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );