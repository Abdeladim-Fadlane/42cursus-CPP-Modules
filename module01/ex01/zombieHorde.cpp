#include"Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombieArray = new Zombie[N];  // Create an array of N Zombie objects

    for (int i = 0; i < N; i++)
    {
        zombieArray[i].setName(name);  // Set the name for each Zombie in the array
        // You can set other attributes here if needed
    }
    return zombieArray;
}
