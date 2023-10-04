// #include <iostream>

// class Animal
// {
// public:
//     static std::string animal_speak(Animal* animal)
//     {
//         return animal->speak();
//     }
//     virtual std::string speak()
//     {
//         return "Animal sound";
//     }
//     virtual void f1()
//     {
//         std::cout<<std::endl;
//     }
// };

// class Dog : public Animal {
// public:
//     std::string speak()  {
//         return "Woof!";
//     }
// };

// class Cat : public Animal {
// public:
//     std::string speak()  {
//         return "Meow!";
//     }
// };

// // Polymorphic behavior


// int main() {
//     Dog dog;
//     Cat cat;

//     std::cout << Animal::animal_speak(&dog) << std::endl;  // Output: Woof!
//     // std::cout << animal_speak(&cat) << std::endl;  // Output: Meow!

//     return 0;
// }
#include <iostream>

class Animal {
public:
    Animal() {
        std::cout << "Animal constructor called" << std::endl;
    }
};

int main() {
    const Animal* meta = new Animal();
    meta.
    // Accessing methods or member variables of the object pointed to by 'meta'
    // is allowed, but modifying them is not allowed due to 'const'.
    
    delete meta; // Don't forget to delete the dynamically allocated object when done.

    return 0;
}
