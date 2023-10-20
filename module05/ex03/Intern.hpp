#ifndef INTERN_HPP
#define INTERN_HPP
#include<string>
#include<iostream>
#include<exception>
#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"AForm.hpp"
class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern&other);
        Intern &operator=(const Intern&other);
        AForm *makeForm(std::string name,std::string target) ;
};
#endif