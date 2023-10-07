#include"WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout<<"WrongCat constructor called\n";
}
WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called\n";
}
WrongCat::WrongCat(const WrongCat& obj):WrongAnimal(obj)
{
    std::cout<<"WrongCat copy constractor called\n";
    *this = obj;
}
WrongCat& WrongCat::operator = (const WrongCat &obj)
{
    std::cout<<"WrongCat copy assignment operator called\n";
    this->type = obj.type;
    return(*this);
}

void WrongCat::setType(std::string s)
{
    type = s;
}

std::string WrongCat::getType()
{
    return(type);
} 

void WrongCat::makeSound()const
{
    std::cout << "The WrongCat meows loudly: meow meow!" << std::endl;
}