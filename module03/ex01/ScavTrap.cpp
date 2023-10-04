#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
ScavTrap::ScavTrap()
{
    std::cout<<"ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const std::string& target):ClapTrap(target)
{   
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout<<"ScavTrap parametrized constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout<<"ScavTrap copy constactor called\n";
    *this = obj;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout<<"ScavTrap Copy assignment operator called \n";;
    this->HitPoints = obj.HitPoints;
    this->EnergyPoints = obj.EnergyPoints;
    this->AttackDamage = obj.AttackDamage;
    return(*this);
};

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap destructor called\n";
    std::cout<<ClapTrap::HitPoints<<"\n";
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<name<< " is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
    if(HitPoints <= 0|| EnergyPoints <= 0)
    {
        std::cout<<"ScavTrap "<<name<<" can't attak !\n";
        return;
    } 
    std::cout<<"ScavTrap "<<name<<" attacks " << target<<" ,causing "<<AttackDamage<<" points of damage!\n";
    EnergyPoints--;
}