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
    *this = obj;
}

Brain& Brain::operator = (const Brain &obj)
{
    *this = obj;
    return(*this);
}