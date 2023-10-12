#include"Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& obj) :AMateria(obj)
{
    *this = obj;
}

Cure& Cure::operator=(const Cure &obj)
{
    this->type = obj.type;
    return(*this);
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}