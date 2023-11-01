#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<vector>
class Span
{
    private :
        unsigned int _N;
        std::vector<unsigned int> _Vec;
    publice:
        Span();
        ~Span();
        Span( unsigned int N);
        Span(const Span & other);
        Span& operator=(const Span &other);
        void    addNumber(unsigned int);
};

#endif