#include"RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &other){*this = other;}
RPN::ErrorException::ErrorException(const std::string &str) : error(str) {}
RPN::ErrorException::ErrorException(const ErrorException &other) {*this=other;}
RPN::ErrorException::~ErrorException() throw() {};
RPN::ErrorException::ErrorException(){};
RPN &RPN::operator=(const RPN& other){this->_stack = other._stack; return *this;}
const char * RPN::ErrorException::what() const throw(){return error.c_str();}
RPN::ErrorException& RPN::ErrorException::operator=(const ErrorException &other)
{
    this->error = other.error;
    return *this;
};

int isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void RPN::ReversePolishNotation(const std::string & expression)
{
    std::istringstream RPN(expression);
    char token;
    while (RPN >> token)
    {
        if(!isdigit(token) && !isOperator(token))
             throw ErrorException("Error");
        if (isOperator(token) && _stack.size() <= 1)
            throw ErrorException("Error");
        if(isdigit(token))
            _stack.push(token - '0'); 
        else if( _stack.size() >= 2 && isOperator(token))
        {
            double topOne = _stack.top();
            _stack.pop();
            double topTwo = _stack.top();
            _stack.pop();
            _stack.push(operation(topTwo,topOne,token));
        }
    }
    if(_stack.size() != 1)
        throw ErrorException("Error ");
    std::cout<<_stack.top()<<"\n";
}

double RPN::operation(double N,double M,char c)
{
    std::string str = "+-*/";
    int i = 0 ;
    while(i < 4)
    {
        if(str[i] == c)
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            return(N+M);
        case 1:
            return(N-M);
        case 2:
            return(N*M);
        case 3:
            if(M == 0)
                throw ErrorException("Error: Cannot divide by zero .");
            return(N/M);
        default:
            break;
    }
    return(-1);
}
