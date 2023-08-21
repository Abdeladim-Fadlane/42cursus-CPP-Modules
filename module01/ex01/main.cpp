
#include"Zombie.hpp"
#include<cstdio>
int main()
{

    Zombie* hordeZombies = zombieHorde(4, "bonawara");

    // Access and display each Zombie's name
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Zombie " << i + 1 << " name: " << hordeZombies[i].getName() << std::endl;
        hordeZombies->announce();
    }
    delete[] hordeZombies;
}