#ifndef RPN_HPP
#define RPN_HPP
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN
{
    private:
        std::stack<double> _stack;
        double operation(double N,double M,char c);
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        void ReversePolishNotation(const std::string &);
        class ErrorException : public std::exception
        {
            private :
                std::string error;
            public :
                ErrorException();
                ErrorException(const std::string &str);
                ErrorException(const ErrorException &other);
                ErrorException&operator=(const ErrorException &other);
                const char *what() const throw();
                virtual ~ErrorException() throw();
        };
};

#endif