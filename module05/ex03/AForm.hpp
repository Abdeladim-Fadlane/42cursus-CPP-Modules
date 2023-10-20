#ifndef AForm_HPP
#define  AForm_HPP
#include<string>
#include<iostream>
#include<exception>
#include"Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        virtual ~AForm();
        AForm(const std::string name,int gradeToSign,int gradeToExecute) ;
        AForm(const AForm&other);
        AForm &operator=(const AForm&other);
        class GradeTooHighException : public  std::exception
                {const char * what() const throw();};
        class GradeTooLowException : public  std::exception
                {const char * what() const throw();};
        class   FormNotSignedException : public  std::exception
                {const char * what() const throw();};
        std::string getName()const;
        bool getSigned()const;
        int getGradeToSign()const;
        int getGradeToExcute()const;
        void beSigned(Bureaucrat &bureaucrat) ;
        virtual void execute(Bureaucrat const & executor)const  = 0;
};
std::ostream& operator<<(std::ostream & obj,const AForm &other);
#endif