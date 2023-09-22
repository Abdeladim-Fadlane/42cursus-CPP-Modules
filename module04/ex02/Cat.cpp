#include"Cat.hpp"

Cat::Cat()
{
    brain = new Brain();
    type = "Cat";
    std::cout<<"Cat constructor called\n";
}
Cat::~Cat()
{
    delete brain;
    std::cout<<"Cat destructor called\n";
}
Cat::Cat(const Cat& obj):Animal(obj)
{
    *this = obj;
}
Cat& Cat::operator = (const Cat &obj)
{
    *this = obj;
    return(*this);
}

void Cat::setType(std::string s)
{
    type = s;
}

std::string Cat::getType()
{
    return(type);
} 

void Cat::makeSound()const
{
    std::cout << "The cat meows loudly: meow meow!" << std::endl;
}