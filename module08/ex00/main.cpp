#include <iostream>
#include <vector>

template <typename T, typename U>
U easyfind(const T& container, U value)
{
    for (size_t i = 0; i < container.size(); i++)
    {
        if (container[i] == value)
            return container[i];
    }
    throw std::out_of_range("No occurrence found\n");
}

int main()
{
    std::vector<char> A ;
    A.push_back('s');
    A.push_back('r');
    A.push_back('c');
    char c;
    try
    {
        c = easyfind(A, 'd');
        std::cout << "Value found: " << c << std::endl;
    } catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
