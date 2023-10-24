#include"Form.hpp"
#include"Bureaucrat.hpp"
Form::Form():_gradeToSign(10),_gradeToExecute(10)
{
    this->_signed = 0;
};

Form::~Form()
{

};

Form::Form(const Form & other):_name(other._name),_gradeToSign(other._gradeToSign),_gradeToExecute(other._gradeToExecute)
{
    this->_signed = other._signed;
}

Form &Form::operator=(const Form&other)
{
    this->_signed = other._signed;
    return(*this);
}

Form::Form(const std::string name,int gradeToSign,int gradeToExecute):_name (name),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute)
{
    this->_signed = 0;
    if(gradeToSign < 1  || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150  || gradeToExecute > 150)
        throw GradeTooLowException();
}; 

std::string Form::getName()const
{
    return(this->_name);
};
bool Form::getSigned()const
{
    return(this->_signed);
};
int Form::getGradeToSign()const
{
    return(this->_gradeToSign);
};
int Form::getGradeToExcute()const
{
    return(this->_gradeToExecute);
};

const char * Form::GradeTooHighException::what() const throw()
{
    return("highest possible grade");
};

const char * Form::GradeTooLowException::what() const throw()
{
    return("lowest possible grade");
};

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= _gradeToSign)
        _signed = 1;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream & obj,const Form &other)
{
    obj <<"Name is : "<<other.getName() <<" | signed : "<<other.getSigned() <<" | GradeToSign : "<< other.getGradeToSign()<<" | GradeToExcute : "<<other.getGradeToExcute()<<std::endl;
    return(obj);
}