#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"

int _main()
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;

    }
    return(0);
}

int main()
{
    // _main();
    try
    {
        Bureaucrat a("L3arbi", 140);
        AForm* form;
        Intern afadlane;
        form = afadlane.makeForm("shrubbery creation", "Bender");
        a.signForm(*form);
        a.executeForm(*form);
        delete form;
    }
    catch (const std::exception & e)
    {
       std::cerr << "Exception: " << e.what()<<std::endl;
    }
   
}