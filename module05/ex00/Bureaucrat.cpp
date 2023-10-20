#include"Bureaucrat.hpp"
Bureaucrat::Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const std::string name,int grade):_name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}



Bureaucrat::Bureaucrat(const Bureaucrat&other)
{
    *this = other;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&other)
{
    this->_grade = other._grade;
    return(*this);
};

int Bureaucrat::getGrade() const
{
    return(this->_grade);
};

const std::string Bureaucrat::getName()const
{
    return(this->_name);
}; 

Bureaucrat::~Bureaucrat()
{
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return("highest possible grade");
};

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("lowest possible grade");
};

void Bureaucrat::increment()
{
    this->_grade++;
    if(this->_grade < 1)
        throw GradeTooHighException();
    if(this->_grade > 150)
        throw GradeTooLowException();
};
void Bureaucrat::decrement()
{
    this->_grade--;
    if(this->_grade < 1)
        throw GradeTooHighException();
    if(this->_grade > 150)
        throw GradeTooLowException();
};

std::ostream& operator<<(std::ostream &obj,const Bureaucrat& other)
{
    obj<< other.getName() << " bureaucrat grade : " << other.getGrade()<<std::endl;
    return(obj);
};
