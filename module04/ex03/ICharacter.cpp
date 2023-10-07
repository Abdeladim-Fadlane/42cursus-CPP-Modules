#include"ICharacter.hpp"

ICharacter::ICharacter()
{
}

ICharacter::ICharacter(const ICharacter& obj)
{
    *this = obj;
}

ICharacter& ICharacter::operator=(const ICharacter &obj)
{
    // this. = obj.type;
    return(*this);
}

ICharacter::~ICharacter()
{
}