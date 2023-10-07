#include"AMateria.hpp"
AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) : type(type) {}
AMateria::AMateria(const AMateria& obj) :AMateria(obj)
{
    *this = obj;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
    this->type = obj.type;
    return(*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}