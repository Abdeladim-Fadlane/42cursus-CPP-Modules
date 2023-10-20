#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include<string>
#include<iostream>
#include<exception>

#include"AForm.hpp"
class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm&other);
        RobotomyRequestForm(const std::string target) ;
        RobotomyRequestForm &operator=(const RobotomyRequestForm&other);
         void    execute(Bureaucrat const & executor)const ;
};
#endif