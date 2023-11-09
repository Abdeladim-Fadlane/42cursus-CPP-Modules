#ifndef RPN_HPP
#define RPN_HPP
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        void ReversePolishNotation(const std::string &);
};
int operation(int N,int M,char c);
#endif