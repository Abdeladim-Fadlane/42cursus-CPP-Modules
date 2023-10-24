#include"AForm.hpp"

AForm::AForm():_gradeToSign(10),_gradeToExecute(10)
{
    this->_signed = 0;
};

AForm::AForm(const AForm&other):_name(other._name),_gradeToSign(other._gradeToSign),_gradeToExecute(other._gradeToExecute)
{
    this->_signed = other._signed;
}

AForm &AForm::operator=(const AForm&other)
{
    this->_signed = other.getSigned();
    return(*this);
}

AForm::~AForm()
{

};

AForm::AForm(const std::string name,int gradeToSign,int gradeToExecute):_name (name),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute)
{
    this->_signed = 0;
    if(gradeToSign < 1  || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150  || gradeToExecute > 150)
        throw GradeTooLowException();
}; 

std::string AForm::getName()const
{
    return(this->_name);
};
bool AForm::getSigned()const
{
    return(this->_signed);
};
int AForm::getGradeToSign()const
{
    return(this->_gradeToSign);
};
int AForm::getGradeToExcute()const
{
    return(this->_gradeToExecute);
};

const char * AForm::GradeTooHighException::what() const throw()
{
    return("highest possible grade");
};

const char * AForm::GradeTooLowException::what() const throw()
{
    return("lowest possible grade");
};

const char * AForm::FormNotSignedException::what() const throw()
{
    return("Form not signed ");
};

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= _gradeToSign)
        _signed = 1; 
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream & obj,const AForm &other)
{
    obj <<"Name is : "<<other.getName() <<" | signed : "<<other.getSigned() <<" | GradeToSign : "<< other.getGradeToSign()<<" | GradeToExcute : "<<other.getGradeToExcute()<<std::endl;
    return(obj);
}