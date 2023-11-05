#include"easyfind.hpp"

int main()
{
    std::vector<int> A ;
    A.push_back(13);
    A.push_back(37);
    A.push_back(37);
    
    std::list<int> B;
    B.push_back(2);
    B.push_back(4);
    B.push_back(42);

    easyfind(A,37);
    easyfind(B,37);

    return 0;
}
