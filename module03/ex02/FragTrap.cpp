#include"ClapTrap.hpp"
#include"FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout<<"FragTrap Default constructor called\n";
}
FragTrap::FragTrap(const std::string& target):ClapTrap(target)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout<<"FragTrap paramitrize constructor called\n";
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout<<"FragTrap copy constactor called\n";
    *this = obj;
};

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout<<"FragTrap Copy assignment operator called \n";;
    this->HitPoints = obj.HitPoints;
    this->EnergyPoints = obj.EnergyPoints;
    this->AttackDamage = obj.AttackDamage;
    return(*this);
};

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap constructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"Give me a high five! 🖐️\n";
}
