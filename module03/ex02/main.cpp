#include"ClapTrap.hpp"
#include"FragTrap.hpp"

int main(void)
{
    FragTrap x("BONAWARA");
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.takeDamage(8);
    x.beRepaired(2);
    x.takeDamage(3);
    x.attack("ZOBIR");
    x.attack("ZOBIR");
    x.highFivesGuys();
}