#include"ClapTrap.hpp"
#include"FragTrap.hpp"

FragTrap::FragTrap(const std::string& target):ClapTrap(target)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout<<"FragTrap constructor called\n";
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap constructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"Give me a high five! 🖐️\n";
}
