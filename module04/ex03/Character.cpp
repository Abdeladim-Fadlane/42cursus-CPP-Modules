#include"Character.hpp"

Character::Character()
{
    tmp = NULL;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const std::string & name)
{
    this->_name = name;
    tmp = NULL;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const Character& obj)
{
    tmp = NULL;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    *this = obj;
}

Character& Character::operator=(const Character &obj)
{
    _name = obj._name;
    for(int i = 0;i < 4;i++)
    {
        delete _inventory[i]; 
        if (obj._inventory[i]) 
             _inventory[i] = obj._inventory[i]->clone();
        else 
            _inventory[i] = NULL;
    }
    return(*this);
}

Character::~Character()
{
    delete tmp;
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
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
       delete m;
        return;
    }
    if(tmp != NULL)
    {
        delete tmp;
        tmp = NULL;
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
    {
        tmp = _inventory[idx];
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
     if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
            _inventory[idx]->use(target);
}