#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<string>
#include<iostream>
class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& obj);
        Animal& operator = (const Animal &obj);
        virtual void makeSound()const  = 0;
        void setType(std::string s);
        std::string getType()const;
};
#endif