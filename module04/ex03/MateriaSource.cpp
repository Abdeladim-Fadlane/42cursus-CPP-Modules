#include"MateriaSource.hpp"
MateriaSource::MateriaSource()
{
    for(int i = 0;i < 4 ;i++)
    {
        _MateriaS[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource& obj)
{
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    for(int i = 0;i < 4;i++)
    {
        delete _MateriaS[i];
    }
    for(int i = 0;i < 4;i++)
    {
        *this->_MateriaS[i] = *obj._MateriaS[i];
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{

}

bool MateriaSource::isFull(AMateria** m)
{
    for(int i = 0;i < 4;i++)
    {
        if(m[i] == NULL)
            return(false);
    }
    return(true);
}

void MateriaSource::learnMateria(AMateria* m) 
{
    if(isFull(_MateriaS))
    {
        delete m;
        return;
    }

    for(int i = 0;i < 4 ;i++)
    {
        if(!_MateriaS[i])
        {
            _MateriaS[i] = m;
            return;
        }   
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) 
{
    for(int i = 0;i < 4 ;i++)
    {
        if(_MateriaS[i]->getType() == type)
            return(_MateriaS[i]->clone());
    }
    return(NULL);
}