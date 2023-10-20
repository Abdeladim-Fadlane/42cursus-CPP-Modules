#include"RobotomyRequestForm.hpp"

 
RobotomyRequestForm::RobotomyRequestForm():AForm()
{

};
RobotomyRequestForm::~RobotomyRequestForm()
{

};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&other):AForm(other)
{
    *this = other;
};
RobotomyRequestForm::RobotomyRequestForm(const std::string target) :AForm("RobotomyRequestForm",72,45)
{
    this->_target = target;
};

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm&other)
{
    (void)other;
    return(*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor)const 
{
    if(!getSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() <= getGradeToExcute())
    {
        std::srand(std::time(NULL));
        std::cout<<"Makes some drilling noises\n";
        if( std::rand() % 2 == 0)
            std::cout << "\x1B[32m" << _target << " Form has been robotomized successfully" << "\x1B[0m" << std::endl;
        else
            std::cout << "\x1B[31mFailed to robotomize Form " << _target << "\x1B[0m" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}