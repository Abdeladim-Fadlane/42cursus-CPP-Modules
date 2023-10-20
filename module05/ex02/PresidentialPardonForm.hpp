#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include<string>
#include<iostream>
#include<exception>

#include"AForm.hpp"
class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm&other);
        PresidentialPardonForm(const std::string target) ;
        PresidentialPardonForm &operator=(const PresidentialPardonForm&other);
        void execute(Bureaucrat const & executor)const ;
};
#endif