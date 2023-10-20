#include"Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("L3arbi", 2);
        Form b("Leet certificate.",102, 1);
        a.signForm(b);
        std::cout<<a;
        // std::cout<<b;

    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception: " << e.what()<<std::endl;
    }

} 