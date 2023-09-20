#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

int main(void)
{
    ScavTrap x("BONAWARA");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.takeDamage(8);
    x.beRepaired(2);
    x.takeDamage(3);
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.guardGate();

}