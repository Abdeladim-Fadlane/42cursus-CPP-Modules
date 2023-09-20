#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& target):ClapTrap(target)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout<<"ScavTrap constructor called\n";
};
ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap constructor called\n";
};
void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<name<< " is now in Gate keeper mode\n";
}
void ScavTrap::attack(const std::string& target)
{
    if(HitPoints <= 0|| EnergyPoints <=0)
    {
        std::cout<<"ScavTrap "<<name<<" is already out of hit points can't attak !\n";
        return;
    } 
    std::cout<<"ScavTrap "<<name<<" attacks " << target<<" ,causing "<<AttackDamage<<" points of damage!\n";
    EnergyPoints--;
}