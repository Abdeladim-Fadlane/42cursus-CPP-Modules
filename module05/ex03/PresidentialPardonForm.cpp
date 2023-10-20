#include"PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm()
{

};
PresidentialPardonForm::~PresidentialPardonForm()
{

};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&other):AForm(other)
{
    *this = other;
};
PresidentialPardonForm::PresidentialPardonForm(const std::string target) :AForm("PresidentialPardonForm",25,5)
{
    this->_target = target;
};

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm&other)
{
    (void)other;
    return(*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor)const 
{
    if(!getSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() <= getGradeToExcute())
    {
        std::cout << "\x1B[32m"<< _target << " Form has been pardoned by Zaphod Beeblebrox."<< "\x1B[0m" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}