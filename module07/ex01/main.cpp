#include <iostream>
#include"iter.hpp"
template <typename T>

void func(T & k)
{
    k -= 49;
}

int main()
{
    int k[] = {50, 52, 52, 56};
    iter(k, 4, func<int>);

    for (int i = 0; i < 4; i++)
    {
        std::cout << k[i] << " ";
    }
    std::cout << std::endl;

    char str[] = "bddh";
    iter(str, 4, func<char>);
    for (int i = 0; i < 4; i++)
    {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
