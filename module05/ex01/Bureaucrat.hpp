#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP
#include<string>
#include<iostream>
#include"Form.hpp"
class Form;
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:

        Bureaucrat();
        ~Bureaucrat();
        std::string getName()const;
        Bureaucrat(const std::string name,int grade); 
        Bureaucrat(const Bureaucrat&other);
        Bureaucrat &operator=(const Bureaucrat&other); 
        int getGrade() const;
        class GradeTooHighException : public  std::exception
                {const char * what() const throw();};
        class GradeTooLowException : public  std::exception
                {const char * what() const throw();};
        void increment();
        void decrement();
        void signForm(Form &form);
};
std::ostream& operator<<(std::ostream &obj,const Bureaucrat &other);

#endif