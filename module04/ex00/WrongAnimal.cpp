#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout<<"WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout<<"WrongAnimal copy constractor called\n";
    *this = obj;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &obj)
{
    std::cout<<"WrongAnimal copy assignment operator called\n";
    this->type = obj.type;
    return(*this);
}

void WrongAnimal::makeSound()const
{
    std::cout <<type<<" makes Wrong sound\n";
}

void WrongAnimal::setType(std::string s)
{
    type = s;
}

std::string WrongAnimal::getType()const
{
    return(type);
} 