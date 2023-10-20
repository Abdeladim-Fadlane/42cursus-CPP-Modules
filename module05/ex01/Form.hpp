#ifndef FORM_HPP
#define  FORM_HPP
#include<string>
#include<iostream>
#include<exception>
#include"Bureaucrat.hpp"
class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form();
        ~Form();
        Form(const Form&other);
        Form &operator=(const Form&other);
        Form(const std::string name,int gradeToSign,int gradeToExecute) ;
        class GradeTooHighException : public  std::exception
                {const char * what() const throw();};
        class GradeTooLowException : public  std::exception
                {const char * what() const throw();};
        std::string getName()const;
        bool getSigned()const;
        int getGradeToSign()const;
        int getGradeToExcute()const;
        void beSigned(Bureaucrat &bureaucrat);
        
};
std::ostream& operator<<(std::ostream & obj,const Form &other);
#endif