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
class RPN
{
    private:
        int flag;
        std::stack<int> _stack;
        int operation(int N,int M,char c);
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
                ErrorException(const std::string &str);
                const char *what() const throw();
        };
};

#endif