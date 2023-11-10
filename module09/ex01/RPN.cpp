#include"RPN.hpp"


RPN::RPN():flag(0)
{

}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN& other)
{
    this->_stack = other._stack; 
    return *this;
}
const char * RPN::ErrorException::what() const throw()
{
    return error.c_str();
}

RPN::ErrorException::ErrorException(const std::string &str) : error(str) {}

int isOperation(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}


void RPN::ReversePolishNotation(const std::string & expression)
{
    size_t i = 0;

    while ( i < expression.length())
    {
        if(expression[i] != ' ' && !isdigit(expression[i]) && !isOperation(expression[i]))
             throw ErrorException("Error: Invalid character in expression.");
        if (isOperation(expression[i]))
        {
            ++flag;
            if (flag == 2)
                throw ErrorException("Error: Invalid character in expression.");
        } 
        else
            flag = 0;
        if(isdigit(expression[i]))
        {
            flag = 0;
            _stack.push(expression[i] - '0'); 
        }
        else if( _stack.size() >= 2 && isOperation(expression[i]))
        {
            int topOne = _stack.top();
            _stack.pop();
            int topTwo = _stack.top();
            _stack.pop();
            _stack.push(operation(topTwo,topOne,expression[i]));
        }
        i++;
    }
    if(_stack.size() != 1)
        throw ErrorException("Error: invalid expression.");
    std::cout<<_stack.top()<<"\n";
}

int RPN::operation(int N,int M,char c)
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



