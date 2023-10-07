#include"Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; ++i)
    {
        slot[i] = nullptr;
    }
}

Character::Character(const Character& obj)
{
    *this = obj;
}

Character& Character::operator=(const Character &obj)
{
    // this.
    // return(*this);
}

Character::~Character()
{

}

std::string const & Character::getName() const
{
    // return(name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (slot[i] == nullptr)
        { 
            slot[i] = m; 
            break; 
        }
    }
}

void Character::unequip(int idx) 
{

}

void Character::use(int idx, ICharacter& target)
{

}