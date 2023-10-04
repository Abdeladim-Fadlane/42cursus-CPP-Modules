#include"DiamondTrap.hpp"
#include"ClapTrap.hpp"

DiamondTrap::DiamondTrap()
{    
    std::cout<<"DiamondTrap Default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& target):ScavTrap(target)
{      
    HitPoints = 100;
    AttackDamage = 30;
    ClapTrap::name = target + "_clap_name";
    this->name = target;
    std::cout<<"DiamondTrap parametrize constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj):ClapTrap(obj),FragTrap(obj),ScavTrap(obj)
{
    std::cout<<"DiamondTrap FragTrap copy constactor called\n";
    *this = obj;
}

DiamondTrap& DiamondTrap::operator =(const DiamondTrap& obj)
{   
    std::cout<<"DiamondTrap Copy assignment operator called \n";
    this->HitPoints = obj.HitPoints;
    this->EnergyPoints = obj.EnergyPoints;
    this->AttackDamage = obj.AttackDamage;
    return(*this);
}

void DiamondTrap::whoAmI()
{
    std::cout<<"DiamondTrap name is :"<<this->name<<"\n";
    std::cout<<"ClapTrap    name is :"<<ClapTrap::name<<"\n";
}
