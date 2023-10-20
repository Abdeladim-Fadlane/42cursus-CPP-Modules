#include"Intern.hpp"

Intern::Intern()
{

};
Intern::~Intern()
{

};
Intern::Intern(const Intern&other)
{
    *this = other;
};

Intern & Intern::operator=(const Intern&other)
{
    (void)other;
    return(*this);
}

AForm *Intern::makeForm(std::string name,std::string target)
{
    std::string arr[3] = {"shrubbery creation","robotomy request","presidential pardon"};
    int i = 0;
    while(i < 3)
    {
        if (name == arr[i])
            break;
        i-=-1;
    }
    switch (i)
    {
        case    0:
            std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
            return new ShrubberyCreationForm(target);
        case    1:
            std::cout << "Intern creates Robotomy Request Form" << std::endl;
            return new RobotomyRequestForm(target);
        case    2:
            std::cout << "Intern creates Presidential Pardon Form" << std::endl;
            return new PresidentialPardonForm(target);
    }
    std::cout << "Error: Unknown Form name." << std::endl;
    return(NULL);
}