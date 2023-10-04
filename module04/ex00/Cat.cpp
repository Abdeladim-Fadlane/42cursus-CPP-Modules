#include"Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout<<"Cat constructor called\n";
}
Cat::~Cat()
{
    std::cout<<"Cat destructor called\n";
}
Cat::Cat(const Cat& obj):Animal(obj)
{
    std::cout<<"Cat copy constractor called\n";
    *this = obj;
}
Cat& Cat::operator = (const Cat &obj)
{
    std::cout<<"Cat copy assignment operator called\n";
    this->type = obj.type;
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