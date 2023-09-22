#ifndef CAT_HPP
#define CAT_HPP
#include<string>
#include"Animal.hpp"
#include"Brain.hpp"
class Cat:public Animal
{
    private:
        Brain *brain;
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