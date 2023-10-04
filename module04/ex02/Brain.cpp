#include"Brain.hpp"

Brain::Brain()
{

    std::cout<<"Brain constructor called\n";
}

Brain::~Brain()
{
    std::cout<<"Brain destructor called\n";
}

Brain::Brain(const Brain& obj)
{
    std::cout<<"Brain copy constractor  called\n";
    *this = obj;
}

Brain& Brain::operator = (const Brain &obj)
{
    std::cout<<"Brain copy assignment operator called\n";
    for(int i = 0;i < 100;i++)
    {
        this->ideas[i] = obj.ideas[i];
    }
    return(*this);
}