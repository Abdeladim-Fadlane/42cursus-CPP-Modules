#include"RPN.hpp"


RPN::RPN()
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
        // std::cout<<expression[i]<<" <<-----------------\n";

        if(expression[i] != ' ' && !isdigit(expression[i]) && !isOperation(expression[i]))
        {
            throw std::out_of_range("Error .");
        }
        if(isdigit(expression[i]) )
        {
            int n = expression[i] - '0';
            _stack.push(n);
        }
        else if( _stack.size() >= 2 && isOperation(expression[i]))
        {
            int tmp = _stack.top();
            _stack.pop();
            int some = _stack.top();
            _stack.pop();
            _stack.push(operation(some,tmp,expression[i]));
        }
        i++;
    }
    if(_stack.size() > 1)
        throw std::out_of_range("Error: invalid expression");
    std::cout<<_stack.top()<<"\n";
}

int operation(int N,int M,char c)
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
            return(N/M);
        default:
            break;
    }
    return(-1);
}



