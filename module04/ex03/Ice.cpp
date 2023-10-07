#include"Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& obj) :AMateria(obj)
{
    *this = obj;
}

Ice& Ice::operator=(const Ice &obj)
{
    this->type = obj.type;
    return(*this);
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}