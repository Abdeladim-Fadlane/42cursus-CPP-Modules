#include"Cat.hpp"
#include"Dog.hpp"
int main()
{
    const Animal* x[2] = {new Cat(),new Dog()};
    for (int i = 0; i < 2; ++i)
    {
        x[i]->makeSound(); 
        delete x[i];      
    }
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;
}