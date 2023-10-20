#include"Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("Bonawara", 2);
        std::cout<<A;
        
        A.decrement();
        std::cout << "Decremented Grade: " << A.getGrade() << std::endl;

        A.increment();
        std::cout << "Incremented Grade: " << A.getGrade() << std::endl;

        A.increment();
        std::cout << "Incremented Grade: " << A.getGrade() << std::endl;
                A.decrement();

        std::cout << "Decremented Grade: " << A.getGrade() << std::endl;

         A.decrement();
        std::cout << "Decremented Grade: " << A.getGrade() << std::endl;

        A.decrement();
        std::cout << "Decremented Grade: " << A.getGrade() << std::endl;
        
    }
    catch (const std::exception & e)
    {
        std::cerr << "Exception: " << e.what()<<std::endl;
    }  
} 