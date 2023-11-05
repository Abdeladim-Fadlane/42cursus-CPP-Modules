#include"Span.hpp"

Span::Span()
{
    this->_N = UINT_MAX;
}

Span::Span(const Span & other)
{
    *this = other;
}

Span& Span::operator=(const Span &other)
{
    this->_N = other._N;
    this->_container = other._container;
    return *this;
}

Span::~Span()
{
    
}
Span::Span(unsigned int N)
{
    this->_N = N;
}

void    Span::addNumber(unsigned int N)
{    
    if( _container.size() >= _N)
        throw std::out_of_range("container is full.");
    std::vector<unsigned int>::const_iterator it ;
    it = std::find(_container.begin(),_container.end(),N);
    if(it !=_container.end())
        throw std::out_of_range("The element is already exit .");
     _container.push_back(N);   
}

unsigned int Span::longestSpan()
{
    if(_container.size() <= 1)
        throw std::out_of_range("no span can be found.");
    std::sort(_container.begin(),_container.end());
    return(*(_container.end() - 1) - *(_container.begin()));
}

unsigned int Span::shortestSpan() 
{
    if(_container.size() <= 1)
        throw std::out_of_range("No span can be found\n");

    std::sort(_container.begin(), _container.end());
    
    unsigned int shortestSpan = UINT_MAX; 
    unsigned int someSpan;
    std::vector<unsigned int>::const_iterator it;
    for (it  = _container.begin() + 1; it != _container.end(); it++)
    {
        someSpan = *it - *(it - 1);
        if (someSpan < shortestSpan)
            shortestSpan = someSpan;
    }
    return shortestSpan;
}

void Span::display()
{
    std::vector<unsigned int >::const_iterator it;
    for(it = _container.begin();it != _container.end();it++)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}