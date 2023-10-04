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
    // Cat a;
    // Cat b = a;
    // ///////test shallow copy and deep copie
    // Cat c;
    // c = a;
}