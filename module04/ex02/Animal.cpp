#include"Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout<<"Animal constructor called\n";
}
Animal::~Animal()
{
    std::cout<<"Animal destructor called\n";
}
Animal::Animal(const Animal& obj)
{
    *this = obj;
}
Animal& Animal::operator = (const Animal &obj)
{
    *this = obj;
    return(*this);
}

void Animal::makeSound()const
{
    std::cout <<type<<" makes sound\n";
}

void Animal::setType(std::string s)
{
    type = s;
}
std::string Animal::getType()const
{
    return(type);
} 