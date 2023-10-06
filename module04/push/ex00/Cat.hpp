#ifndef CAT_HPP
#define CAT_HPP
#include<string>
#include"Animal.hpp"
class Cat:public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& obj);
        Cat& operator = (const Cat &obj);
        void makeSound()const;
        void setType(std::string s);
        std::string getType();
};
#endif