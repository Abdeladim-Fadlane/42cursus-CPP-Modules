#include"Dog.hpp"

Dog::Dog()
{
    brain = new Brain();
    type = "Dog";
    std::cout<<"Dog constructor called\n";
}

Dog::~Dog()
{
    
    std::cout<<"Dog destructor called\n";
    delete brain;
}

Dog::Dog(const Dog& obj):Animal()
{
    *this = obj;
}

Dog& Dog::operator = (const Dog &obj)
{
    *this = obj;
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