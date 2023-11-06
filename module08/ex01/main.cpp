#include"Span.hpp"

int main(int ,char **)
{
    try
    {
        Span sp = Span(14);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(170);
        sp.addNumber(9);
        sp.addNumber(17);
        sp.display();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        unsigned int arr[] = {25, 7, 50, 44,22,333};
        sp.addRangeNumber(arr,6);
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