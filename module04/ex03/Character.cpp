#include"Character.hpp"

Character::Character()
{
    tmp = NULL;
    for (int i = 0; i < 4; ++i)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(const std::string & name)
{
    this->_name = name;
    tmp = NULL;
    for (int i = 0; i < 4; ++i)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& obj)
{
    *this = obj;
}

Character& Character::operator=(const Character &obj)
{
    this->_name = obj._name;
    for(int i = 0;i < 4;i++)
        delete _inventory[i];
    for(int i = 0;i < 4;i++)
        *this->_inventory[i] = *obj._inventory[i];
    *this->tmp = *obj.tmp;
    return(*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
    delete tmp;
}

std::string const & Character::getName() const
{
    return(_name);
}

bool Character::isFull(AMateria** m)
{
    for(int i = 0;i < 4;i++)
    {
        if(m[i] == NULL)
            return(false);
    }
    return(true);
}

void Character::equip(AMateria* m)
{
    if(isFull(_inventory))
    {
        if(tmp)
        {
            delete tmp;
            tmp = m;
        }
        tmp = m;
        return;
    }

    for (int i = 0; i < 4;i++)
    {
        if (_inventory[i] == NULL)
        { 
            _inventory[i] = m; 
            return; 
        }
    }
}

void Character::unequip(int idx) 
{
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
            _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
     if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
            _inventory[idx]->use(target);
}