#include"ClapTrap.hpp"
#include"FragTrap.hpp"
#include"DiamondTrap.hpp"

int main(void)
{
    DiamondTrap x("BONAWARA");
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
    //x.guardGate();
    //x.whoAmI();
}