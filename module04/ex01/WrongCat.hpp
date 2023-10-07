#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include<string>

#include"WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& obj);
        WrongCat& operator = (const WrongCat &obj);
        void makeSound()const;
        void setType(std::string s);
        std::string getType();
};
#endif