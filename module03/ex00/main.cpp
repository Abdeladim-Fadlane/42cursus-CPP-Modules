#include"ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("BONAWARA");
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    claptrap.takeDamage(8);
    claptrap.beRepaired(2);
    claptrap.takeDamage(3);
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    //claptrap.takeDamage(1);
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    claptrap.attack("ZOBIR");
    return(0);
}