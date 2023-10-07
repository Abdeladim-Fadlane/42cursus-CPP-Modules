#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include<string>
#include<iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& obj);
        WrongAnimal& operator = (const WrongAnimal &obj);
        void makeSound()const;
        void setType(std::string s);
        std::string getType()const;
};
#endif