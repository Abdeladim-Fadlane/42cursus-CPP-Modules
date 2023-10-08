#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include"IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_MateriaS[4];
        bool isFull(AMateria** m);
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& obj);
        MateriaSource& operator=(const MateriaSource &obj);
        ~MateriaSource();
        void learnMateria(AMateria*m) ;
        AMateria* createMateria(std::string const & type) ;
};
#endif