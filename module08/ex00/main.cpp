#include"easyfind.hpp"

int main()
{
    std::vector<std::string> A ;
    A.push_back("13");
    A.push_back("37");
    A.push_back("1337");
    std::string c;
    std::string str = "1337";
    try
    {
        c = easyfind(A, str);
        std::cout << "Value found: " << c << std::endl;
    } catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
