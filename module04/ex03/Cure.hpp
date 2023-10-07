#ifndef CURE_HPP
#define CURE_HPP
#include<string>

#include"AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& obj);
        Cure& operator=(const Cure &obj);
        virtual ~Cure() {}
        AMateria *clone() const ;
        void use(ICharacter &target) ;
};

#endif