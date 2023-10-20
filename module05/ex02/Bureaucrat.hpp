#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP
#include<string>
#include<iostream>

#include"AForm.hpp"
class AForm;
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:

        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat&other);
        Bureaucrat &operator=(const Bureaucrat&other);
        Bureaucrat(const std::string name,int grade);
        std::string getName()const;
         
        int getGrade() const;
        class GradeTooHighException : public  std::exception
                {const char * what() const throw();};
        class GradeTooLowException : public  std::exception
                {const char * what() const throw();};
        void increment();
        void decrement();
        void signForm(AForm &form);
        void executeForm(AForm const & form);
};
std::ostream& operator<<(std::ostream &obj,const Bureaucrat &other);

#endif