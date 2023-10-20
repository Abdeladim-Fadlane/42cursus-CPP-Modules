#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat a("L3arbi", 26);
        ShrubberyCreationForm b("Leet certificate");
        // RobotomyRequestForm b("Leet certificate");
        // PresidentialPardonForm b("Leet certificate");
        a.signForm(b);
        a.executeForm(b);
    }
    catch (const std::exception & e)
    {
       std::cerr << "Exception: " << e.what()<<std::endl;
    }
}