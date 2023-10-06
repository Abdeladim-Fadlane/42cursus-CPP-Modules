#include"Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout<<"Dog constructor called\n";
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called\n";
}

Dog::Dog(const Dog& obj):Animal()
{
    std::cout<<"Dog copy constractor called\n";
    *this = obj;
}

Dog& Dog::operator = (const Dog &obj)
{
    std::cout<<"Dog copy assignment operator called\n";
    this->type = obj.type;
    return(*this);
}

void Dog::setType(std::string s)
{
    type = s;
}

std::string Dog::getType()const
{
    return(type);
} 

void Dog::makeSound()const
{
    std::cout << "The dog barks: Woof woof!" << std::endl;
}