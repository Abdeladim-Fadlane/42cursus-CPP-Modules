#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include<string>
#include<iostream>
#include<exception>

#include"AForm.hpp"
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm&other);
        ShrubberyCreationForm(const std::string target) ;
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm&other);
        void    execute(Bureaucrat const & executor)const ;
};
#endif