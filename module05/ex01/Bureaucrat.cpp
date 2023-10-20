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
std::string Bureaucrat::getName()const
{
    return(this->_name);
}; 

int Bureaucrat::getGrade() const
{
    return(this->_grade);
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

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout<<this->getName()<<" signed "<<form.getName()<<std::endl;
    }
    catch (const std::exception & e)
    {
        std::cerr <<_name<< " couldn’t sign " <<form.getName() <<" because "<< e.what()<<std::endl;
    }
}
std::ostream& operator<<(std::ostream &obj,const Bureaucrat other)
{
    
    obj << other.getName() << " bureaucrat grade : " << other.getName()<<std::endl;std::cout<<other.getName()<<"\n";
    return(obj);
};




