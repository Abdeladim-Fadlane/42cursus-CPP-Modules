#ifndef DOG_HPP
#define DOG_HPP
#include<string>
#include"Animal.hpp"
class Dog:public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& obj);
        Dog& operator = (const Dog &obj);
        void setType(std::string s);
        std::string getType()const;
        void makeSound()const;
};
#endif