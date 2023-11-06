#ifndef SPAN_HPP
#define SPAN_HPP
#include <climits>
#include<iostream>
#include<vector>
#include <algorithm>

class Span
{
    private :
        unsigned int _N;
        std::vector<unsigned int> _container;
    public:
        Span();
        ~Span();
        Span( unsigned int N);
        Span(const Span & other);
        Span& operator=(const Span &other);
        void    addNumber(unsigned int);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void display();
        void addRangeNumber(unsigned int arr[],unsigned int len);
};

#endif