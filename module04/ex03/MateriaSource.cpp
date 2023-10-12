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
    for(int i = 0;i < 4 ;i++)
    {
        _MateriaS[i] = NULL;
    }
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    for(int i = 0;i < 4;i++)
    {
        delete _MateriaS[i];
        if(obj._MateriaS[i])
            _MateriaS[i] = obj._MateriaS[i]->clone();
        else
            _MateriaS[i] = NULL;
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete _MateriaS[i];
    }
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
    for(int  i = 0;i < 4;i++)
    {
        if(_MateriaS[i] &&_MateriaS[i]->getType() == type)
            return(_MateriaS[i]->clone());
    }
    return(NULL);
}