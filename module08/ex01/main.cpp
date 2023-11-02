#include"Span.hpp"



int main(int ,char **)
{
    try
    {
        Span sp = Span(13);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(170);
        sp.addNumber(9);
        sp.addNumber(17);
        sp.display();

        unsigned int arr[] = {25, 7, 50, 44,22,3};
        sp.addRangeNumber(arr,arr + 6);
        sp.display();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::vector<unsigned int> vec;
        vec.push_back(12);
        vec.push_back(10);
        vec.push_back(1);
        vec.push_back(14);
        sp.addRangeNumber(vec.begin(),vec.end());
        sp.display();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}