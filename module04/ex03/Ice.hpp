#ifndef ICE_HPP
#define ICE_HPP
#include"AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& obj);
        Ice&operator=(const Ice &obj);
        ~Ice() ;
        AMateria *clone() const;
        void use(ICharacter &target);
};
#endif